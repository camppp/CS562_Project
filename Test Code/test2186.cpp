#include <iostream>

class IntegerNumeral {
private:
    int _IntegerNumeral;  // Member variable to store the integer value

public:
    // Default copy constructor
    IntegerNumeral(const IntegerNumeral& src) = default;

    // Default move constructor
    IntegerNumeral(IntegerNumeral&& src) = default;

    // Default copy assignment operator
    IntegerNumeral& operator=(const IntegerNumeral& src) = default;

    // Default move assignment operator
    IntegerNumeral& operator=(IntegerNumeral&& src) = default;

    // Constructor to initialize with unsigned short
    explicit IntegerNumeral(unsigned short src) : _IntegerNumeral(src) {}

    // Constructor to initialize with signed short
    explicit IntegerNumeral(signed short src) : _IntegerNumeral(src) {}

    // Constructor to initialize with unsigned long
    explicit IntegerNumeral(unsigned long src) : _IntegerNumeral(src) {}

    // Other member functions can be added as per requirements

    // Getter function to retrieve the integer value
    int getValue() const {
        return _IntegerNumeral;
    }
};

int main() {
    // Example usage of the IntegerNumeral class
    IntegerNumeral num1(10);  // Initialize with unsigned short
    IntegerNumeral num2(-5);  // Initialize with signed short
    IntegerNumeral num3(1000L);  // Initialize with unsigned long

    std::cout << "Value of num1: " << num1.getValue() << std::endl;
    std::cout << "Value of num2: " << num2.getValue() << std::endl;
    std::cout << "Value of num3: " << num3.getValue() << std::endl;

    return 0;
}
