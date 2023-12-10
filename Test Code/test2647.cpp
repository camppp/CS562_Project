.handle<digit_pressed>([&](digit_pressed const& msg) {
  unsigned const pin_length = 4;
  pin += msg.digit;
  if (pin.length() == pin_length) {
    if (pin == "1234") {
      // Grant access
      std::cout << "Access granted!" << std::endl;
    } else {
      // Deny access
      std::cout << "Access denied!" << std::endl;
    }
  }
});
