# Example: LED control & Status

## Requirements

Atom
PlatformIO
ArduinoJSON

## Usage


Download the firmware onto the Arduino
Edit the port and baudrate in configuration file

## With a local MQTT broker:


Every command in its own terminal, run: 
### MQTT Listener

mosquitto_sub -v -h localhost -p 1883 -t '#'

To print all the MQTT messages and associated topic.

### Start the proxy
Run:

npm start


### MQTT Publisher
Turn on builtin led:

mosquitto_pub -h localhost -m '{"led_state":1}' -t robot/in 


Turn off builtin led:

mosquitto_pub -h localhost -m '{"led_state":0}' -t robot/in 

