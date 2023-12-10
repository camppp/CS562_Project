int channel = 1;

void loop() {
  if (!digitalRead(PIN_TRIGGER_B)) {
    if (channel == 1) {
      channel = 2;
    } else {
      channel = 1;
    }
    updateLED();
    delay(1000); // Delay to stabilize the state of the traffic lights
  }
}
