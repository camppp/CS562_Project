#include <Arduino.h>

class HardwareInput {
public:
  HardwareInput(uint8_t pin, bool enable_pullup);
  bool readInput();

private:
  uint8_t pin;
};

HardwareInput::HardwareInput(uint8_t pin, bool enable_pullup) : pin(pin) {
  if (enable_pullup)
    pinMode(pin, INPUT_PULLUP);
  else
    pinMode(pin, INPUT);
}

bool HardwareInput::readInput() {
  return digitalRead(pin) == HIGH;
}

void setup() {
  // Initialize hardware input
  HardwareInput input(2, true);
  bool state = input.readInput();
  // Use the input state
}

void loop() {
  // Main program loop
}
