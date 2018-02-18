char command[50];

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (0 < Serial.available()) {
    memset(command, '\0', 50);
    Serial.readBytesUntil('\n', command, 50); // Input message from MQTT
    /* TODO: DO WHATEVER */
    Serial.println(command); // Output message to MQTT
  }
}