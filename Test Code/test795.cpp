void GPIO::write(int pin, int data) {
  // Check if the pin number is valid
  if (pin < 0 || pin >= pins.size()) {
    return;
  }

  // Get the current value of the pin
  int currentValue = pins[pin];

  // Set the new value of the pin based on the GPIO type
  if (type == DIGITAL_INPUT || type == DIGITAL_OUTPUT) {
    if (data > 0) {
      currentValue = elrond::high;
    } else {
      currentValue = elrond::low;
    }
  } else if (type == PWM || type == SERVO) {
    currentValue = data;
  } else {
    return;
  }

  // Set the new value of the pin
  pins[pin] = currentValue;

  // Trigger the onWrite callback function if it is not nullptr
  if (onWrite != nullptr) {
    onWrite(pin, currentValue);
  }
}
