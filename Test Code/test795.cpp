#include <iostream>
#include <map>
#include <functional>

enum class GpioType { DIGITAL_INPUT, DIGITAL_OUTPUT, PWM, SERVO };
enum class elrond { high, low };

class Gpio {
private:
    std::map<int, int> pins;
    std::function<void(int, int)> onWrite;

public:
    void write(int pin, int data, GpioType type) {
        auto it = this->pins.find(pin);
        if (it == this->pins.end()) return;

        switch (type) {
            case GpioType::DIGITAL_INPUT:
            case GpioType::DIGITAL_OUTPUT:
                it->second = data > 0 ? static_cast<int>(elrond::high) : static_cast<int>(elrond::low);
                break;

            case GpioType::PWM:
            case GpioType::SERVO:
                it->second = data;
                break;

            default:
                return;
        }

        if (this->onWrite != nullptr) this->onWrite(pin, it->second);
    }
};

int main() {
    // Example usage
    Gpio gpio;
    gpio.write(1, 1, GpioType::DIGITAL_OUTPUT);
    gpio.write(2, 255, GpioType::PWM);
    return 0;
}
