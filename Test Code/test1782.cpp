#include <iostream>
#include <string>
#include <stdexcept>

class Decimal {
public:
    // Constructor
    Decimal(const std::string& byteRepresentation) {
        // Convert the byte representation to a string
        std::string str = byteRepresentation;

        // Check if the string is a valid decimal number
        if (!isValidDecimal(str)) {
            throw std::invalid_argument("Invalid decimal number");
        }

        // Convert the string to a decimal number
        this->value = std::stod(str);
    }

    // Convert a decimal number to a custom byte representation
    std::string toByteRepresentation() const {
        // Convert the decimal number to a string
        std::string str = std::to_string(this->value);

        // Check if the string is a valid byte representation
        if (!isValidByteRepresentation(str)) {
            throw std::invalid_argument("Invalid byte representation");
        }

        // Return the byte representation
        return str;
    }

    // Convert a custom byte representation to a decimal number
    static Decimal fromByteRepresentation(const std::string& byteRepresentation) {
        // Convert the byte representation to a decimal number
        double value = std::stod(byteRepresentation);

        // Check if the decimal number is valid
        if (!isValidDecimal(value)) {
            throw std::invalid_argument("Invalid decimal number");
        }

        // Return the decimal number
        return Decimal(value);
    }

private:
    // Check if a string is a valid decimal number
    static bool isValidDecimal(const std::string& str) {
        // Check if the string is a valid number
        if (!std::isdigit(str[0])) {
            return false;
        }

        // Check if the string contains only digits and a decimal point
        for (size_t i = 1; i < str.length(); i++) {
            if (!std::isdigit(str[i]) && str[i] != '.') {
                return false;
            }
        }

        // Check if the string contains only one decimal point
        size_t count = 0;
        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == '.') {
                count++;
            }
        }
        if (count > 1) {
            return false;
        }

        // Check if the string is a valid number
        try {
            std::stod(str);
        } catch (std::invalid_argument& e) {
            return false;
        }

        return true;
    }

    // Check if a string is a valid byte representation
    static bool isValidByteRepresentation(const std::string& str) {
        // Check if the string is a valid number
        if (!std::isdigit(str[0])) {
            return false;
        }

        // Check if the string contains only digits and a decimal point
        for (size_t i = 1; i < str.length(); i++) {
            if (!std::isdigit(str[i]) && str[i] != '.') {
                return false;
            }
        }

        // Check if the string contains only one decimal point
        size_t count = 0;
        for (size_t i = 0; i < str.length(); i++) {
            if (str[i] == '.') {
                count++;
            }
        }
        if (count > 1) {
            return false;
        }

        // Check if the string is a valid number
        try {
            std::stod(str);
        } catch (std::invalid_argument& e) {
            return false;
        }

        return true;
    }

    // The decimal number
    double value;
};
