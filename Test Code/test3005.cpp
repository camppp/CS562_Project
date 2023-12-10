class ButtonHandler {
 public:
  ButtonHandler(const Gpio &button) : button_(button), was_pressed_(false), was_released_(false) {}

  void Update() {
    bool current_state = button_.Read();  // Assuming Gpio has a Read method to get the current state
    if (current_state && !was_pressed_) {
      was_pressed_ = true;
      was_released_ = false;
    } else if (!current_state && !was_released_) {
      was_released_ = true;
      was_pressed_ = false;
    }
  }

  bool WasPressed() const {
    return was_pressed_;
  }

  bool WasReleased() const {
    return was_released_;
  }

  void Reset() {
    was_pressed_ = false;
    was_released_ = false;
  }

 private:
  const Gpio &button_;
  bool was_pressed_;
  bool was_released_;
};
