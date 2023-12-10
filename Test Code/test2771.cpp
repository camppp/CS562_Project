// LED controller class
template <typename _led>
class LedController {
private:
    hwcpp::pin_out< _led > ledPin;  // LED pin

public:
    // Constructor
    LedController() : ledPin() {
        // Initialize the LED pin
    }

    // Function to turn the LED on
    void turnOn() {
        ledPin.set(true);
    }

    // Function to turn the LED off
    void turnOff() {
        ledPin.set(false);
    }

    // Function to toggle the LED state
    void toggle() {
        // Read the current state of the LED pin and toggle it
        bool currentState = /* Read the current state of the LED pin */;
        ledPin.set(!currentState);
    }
};
