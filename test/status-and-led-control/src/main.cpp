#include <Arduino.h>
#include <ArduinoJson.h>

#define INTERVAL 1000 // in ms
#define MS_TO_S(x) (x/1000)

void publish_json(uint8_t ledState, uint32_t secTicker);
void builtin_led_action(uint8_t state);

uint8_t     ledState;
char        command[64];
uint8_t     numBytesRxd;

StaticJsonBuffer<500> rx_jsonBuffer;
StaticJsonBuffer<500> tx_jsonBuffer;

JsonObject& txdJSON = tx_jsonBuffer.createObject();
//JsonObject& rxdJson = rx_jsonBuffer.createObject();

/*
Rxd JSON style:
{
    "sec_ticker": "{ticker in seconds}",
    "led_state": "{on or off}"
}
*/

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);
    ledState = 0;

    //txdJSON = tx_jsonBuffer.createObject();
}

void loop() {
    // put your main code here, to run repeatedly:
    static uint32_t msTicker   = 0;
    static uint32_t prevTicker = 0;

    msTicker = millis();

    if ((msTicker - prevTicker) >= INTERVAL)
    {
      prevTicker = msTicker;
      publish_json(ledState, (uint32_t)MS_TO_S(msTicker));
    }


    if (0 < Serial.available())
    {
      memset(command, '\0', 64);
      numBytesRxd = Serial.readBytesUntil('\n', command, 63); // Input message from MQTT
                                                              // ( care, seems like readBytesUntil
                                                              //  has a timeout )
      command[numBytesRxd] = '\0';

      JsonObject& rxdJson = rx_jsonBuffer.parseObject(command);
      // check if the object was successfully parsed
      if (rxdJson.success())
      {
        // dbg tip: try to send {"sec_ticker": 7,"led_state": 0} on serial monitor,
        // also try to remove last bracket
        ledState = rxdJson["led_state"];
        builtin_led_action(ledState);

      }
    }
}

void publish_json(uint8_t ledState, uint32_t secTicker)
{

  txdJSON["ticker_secs"] = secTicker;
  txdJSON["led_state"]   = ledState;

  txdJSON.printTo(Serial);

  Serial.println();
}


void builtin_led_action(uint8_t state)
{
  //simple on/off there, no brightness
  digitalWrite(LED_BUILTIN, state);
}
