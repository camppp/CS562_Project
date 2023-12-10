#include <iostream>
#include <string>

// Abstract enumeration interface
class AbstractEnumInterface {
public:
    virtual int getValue() const = 0;
    virtual std::string getName() const = 0;
    virtual ~AbstractEnumInterface() = default;
};

// Example of a derived enumeration class
class MyEnum : public AbstractEnumInterface {
public:
    enum EnumValue {
        VALUE1 = 1,
        VALUE2 = 2,
        VALUE3 = 3
    };

    int getValue() const override {
        return static_cast<int>(value);
    }

    std::string getName() const override {
        switch (value) {
            case VALUE1: return "VALUE1";
            case VALUE2: return "VALUE2";
            case VALUE3: return "VALUE3";
            default: return "Unknown";
        }
    }

private:
    EnumValue value;
};

int main() {
    MyEnum enumInstance;
    std::cout << "Value: " << enumInstance.getValue() << ", Name: " << enumInstance.getName() << std::endl;
    return 0;
}
