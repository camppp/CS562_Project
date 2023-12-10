#include <iostream>

// Template for pin_out
template <typename T>
struct pin_out {
    void set(bool value) {
        std::cout << "Setting pin to " << value << std::endl;
    }
};

// LED controller class
template <typename _led>
class LedController {
public:
    // Constructor
    LedController() {
        // Initialize the LED pin
    }

    // Function to turn the LED on
    void turnOn() {
        _led::set(true);
    }

    // Function to turn the LED off
    void turnOff() {
        _led::set(false);
    }

    // Function to toggle the LED state
    void toggle() {
        _led::set(!_led::get());
    }
};

int main() {
    using led = hwcpp::pin_out< _led >;
    LedController<led> controller;
    controller.turnOn();
    controller.toggle();
    controller.turnOff();
    return 0;
}
