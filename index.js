'use strict';

const SerialPort = require('serialport');
const FS = require('fs');
const MQTT = require('mqtt');
const ReadLineItf = require('readline').createInterface;

const setup = JSON.parse(FS.readFileSync('setup.json', 'utf8'));
const mqttClient = MQTT.connect(setup.mqtt);
/*
 * Common port list:
 * /dev/tty.usbserial-A9007UX1 ---> Mac OS X
 * /dev/ttyACM0 ---> Linux (Raspberry Pi)
 * /dev/ttyUSB0 ---> Linux (Ubuntu)
 * COM3 ---> Windows
 */
const serial = new SerialPort(setup.port, {baudRate: setup.rate});
const valueReader = ReadLineItf({
    input: serial
});

// Serial listener (serial --> MQTT)
valueReader.on('line', function (value) {
    /*
     * I don't understand exactly why, but sometimes the value still contains
     * unwanted chars like \0 \r \n. As I don't have time to spend on it, I
     * dirty fix this for the moment with a regexp and even a trim. It then
     * works flawlessly.
     */
    value = value.replace(/[\r\n\0]/gm, '');
    if ('' !== value.trim()) {
        console.log('out --> [' + value + ']');
        mqttClient.publish(setup.tout, value, {qos: setup.qos}); // MQTT pub
    }
});
// -------

// MQTT subscriber (MQTT --> serial)
mqttClient.on('connect', function () {
    mqttClient.subscribe(setup.tin); // MQTT sub
});

mqttClient.on('message', function (topic, message) {
    let value = message.toString();
    console.log('[' + value + '] --> in');
    serial.write(value + '\n');
});
// -------