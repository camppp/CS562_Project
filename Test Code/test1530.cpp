#include <iostream>

class Arduino {
private:
    int _pin_[20]; // Assuming 20 pins for this example

public:
    Arduino() {
        // Initialize pin values to 0
        for (int i = 0; i < 20; i++) {
            _pin_[i] = 0;
        }
    }

    void pinMode(int pin, int mode) {
        // Implement pinMode function
        // For simplicity, we will not handle invalid pin numbers
        // 0 denotes input and 1 denotes output
        // For this example, we will not handle other modes like INPUT_PULLUP
        if (mode == 0 || mode == 1) {
            // Implement pin mode setting
            // For this example, we will not handle setting pin modes
            std::cout << "Setting pin " << pin << " mode to " << mode << std::endl;
        }
    }

    void digitalWrite(int pin, int level) {
        // Implement digitalWrite function
        // For simplicity, we will not handle invalid pin numbers
        // 0 denotes LOW and 1 denotes HIGH
        if (level == 0 || level == 1) {
            // Set the pin value
            _pin_[pin] = level;
            std::cout << "Setting pin " << pin << " to " << level << std::endl;
        }
    }
};

int main() {
    Arduino arduino;

    arduino.pinMode(13, 1); // Set pin 13 as output
    arduino.digitalWrite(13, 1); // Set pin 13 to HIGH

    return 0;
}
