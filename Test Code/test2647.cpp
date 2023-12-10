.handle<digit_pressed>([&](digit_pressed const& msg) {
  unsigned const pin_length = 4;
  static std::string predefined_pin = "1234";  // Predefined 4-digit PIN
  static std::string pin;  // Variable to store the entered PIN
  pin += msg.digit;
  if (pin.length() == pin_length) {
    if (pin == predefined_pin) {
      grant_access();  // Grant access if the entered PIN matches the predefined PIN
    } else {
      deny_access();  // Deny access if the entered PIN does not match the predefined PIN
    }
    pin.clear();  // Clear the entered PIN for the next input
  }
});
