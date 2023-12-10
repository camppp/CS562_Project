#include <iostream>
#include <string>

class Roman_int {
public:
    // Default constructor
    Roman_int() : value(0) {}

    // Constructor that takes a Roman numeral as input
    Roman_int(const std::string& roman) {
        // Initialize the value based on the Roman numeral
        if (roman == "I") {
            value = 1;
        } else if (roman == "V") {
            value = 5;
        } else if (roman == "X") {
            value = 10;
        } else if (roman == "L") {
            value = 50;
        } else if (roman == "C") {
            value = 100;
        } else if (roman == "D") {
            value = 500;
        } else if (roman == "M") {
            value = 1000;
        } else {
            throw std::invalid_argument("Invalid Roman numeral");
        }
    }

    // Member function to return the integer value of the Roman numeral
    int as_int() const { return value; }

    // Overloaded stream insertion operator to print the Roman numeral and its integer value
    friend std::ostream& operator<<(std::ostream& os, const Roman_int& roman) {
        return os << "Roman " << roman.value << " equals " << roman.as_int() << std::endl;
    }

private:
    int value; // The integer value of the Roman numeral
};

int main() {
    // Create a Roman_int instance with a default value
    Roman_int roman1;
    std::cout << roman1 << std::endl; // Output: Roman 0 equals 0

    // Create a Roman_int instance with a specific value
    Roman_int roman2("X");
    std::cout << roman2 << std::endl; // Output: Roman 10 equals 10

    // Create a Roman_int instance with a specific value using the constructor
    Roman_int roman3(roman2);
    std::cout << roman3 << std::endl; // Output: Roman 10 equals 10

    // Convert a Roman numeral to an integer
    Roman_int roman4("IV");
    std::cout << "Roman IV equals " << roman4.as_int() << std::endl; // Output: Roman IV equals 4

    return 0;
}
