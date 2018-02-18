# SerialMQTTGatewayJS
NodeJS serial to MQTT, MQTT to serial bidirectional gateway.

This is a NodeJS NetBeans project, tested with NodeJS v8.9.4 and Mosquitto (an
MQTT protocol implementation from the Eclipse Foundation) on Ubuntu Linux
16.04.3 LTS x64.

This piece of software listens to messages coming from a local serial port and
forwards everything it reads from it to an MQTT broker (on a dedicated output
channel). It also listen to a dedicated input channel of this MQTT broker and
forwards everything it reads from it to the local serial port. This project
mainly depends on the NPM module "serialport" (v6.0.5) to handle the serial
communication and on the NPM module "mqtt" (v2.15.3) to communicate over an MQTT
broker.

In the "test" directory, I added a small Arduino program I used for testing the
whole communication pipe. Use `mosquitto_pub` and `mosquitto_sub` from the
"moquitto-clients" APT package to publish or subscribe easily on a MQTT
instance.

## Installation
Run `sudo apt-get install build-essential` to install the needed dependency in
order to eventually build the NPM module "serialport" if necessary.
Run `npm install` to install the dependencies of the project.

## Setup
Gateway properties are set in the JSON file "setup.json".

## Usage
Run `npm start` to launch the gateway on the local machine.

Tips:
- Use the `dmesg` command to get the serial port ID on a Linux-like OS.

DONATION:
As I share these sources for commercial use too, maybe you could consider
sending me a reward (even a tiny one) to my Ethereum wallet at the address
0x1fEaa1E88203cc13ffE9BAe434385350bBf10868
If so, I would be forever grateful to you and motivated to keep up the good work
for sure :oD Thanks in advance !

FEEDBACK:
You like my work? It helps you? You plan to use/reuse/transform it? You have
suggestions or questions about it? Just want to say "hi"? Let me know your
feedbacks by mail to the address fabvalaaah@laposte.net

DISCLAIMER:
I am not responsible in any way of any consequence of the usage of this piece of
software. You are warned, use it at your own risks.