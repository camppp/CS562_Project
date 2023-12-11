class Arduino {
private:
    int _pin_[16]; // array to store pin values

public:
    Arduino() {
        for (int i = 0; i < 16; i++) {
            _pin_[i] = 0; // initialize all pins to LOW
        }
    }

    void pinMode(int pin, int mode) {
        if (pin < 0 || pin > 15) {
            return; // invalid pin number
        }

        if (mode == 0) {
            _pin_[pin] = 0; // set pin to input
        } else if (mode == 1) {
            _pin_[pin] = 1; // set pin to output
        } else {
            return; // invalid mode
        }
    }

    void digitalWrite(int pin, int level) {
        if (pin < 0 || pin > 15) {
            return; // invalid pin number
        }

        if (level == 0) {
            _pin_[pin] = 0; // set pin to LOW
        } else if (level == 1) {
            _pin_[pin] = 1; // set pin to HIGH
        } else {
            return; // invalid level
        }
    }
};
