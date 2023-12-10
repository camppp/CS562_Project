#include <iostream>
#include <string>
#include <utility>

class Param {
public:
    std::string name;
    FFUInt32 type;
    float value;

    Param(std::string name, FFUInt32 type, float value) :
        name(std::move(name)),
        type(type),
        value(value) {}

    void SetValue(float v) {
        value = v;
    }
};

int main() {
    // Example usage
    Param param1("param1", 1, 10.5);
    std::cout << "Initial value: " << param1.value << std::endl;

    param1.SetValue(20.3);
    std::cout << "Updated value: " << param1.value << std::endl;

    return 0;
}
