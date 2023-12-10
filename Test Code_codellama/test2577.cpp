void loop() {
  if (!digitalRead(PIN_TRIGGER_B)) {
    channel = 1;
    updateLED();
  }

  if (channel == 1) {
    digitalWrite(PIN_TRAFFIC_LIGHT_A_RED, LOW);
    digitalWrite(PIN_TRAFFIC_LIGHT_A_GREEN, HIGH);
    digitalWrite(PIN_TRAFFIC_LIGHT_B_RED, HIGH);
    digitalWrite(PIN_TRAFFIC_LIGHT_B_GREEN, LOW);
  } else {
    digitalWrite(PIN_TRAFFIC_LIGHT_A_RED, HIGH);
    digitalWrite(PIN_TRAFFIC_LIGHT_A_GREEN, LOW);
    digitalWrite(PIN_TRAFFIC_LIGHT_B_RED, LOW);
    digitalWrite(PIN_TRAFFIC_LIGHT_B_GREEN, HIGH);
  }
}
