#include <iostream>
#include <string>
#include <stdexcept>

class Decimal {
private:
    std::string bytes;

public:
    Decimal(const std::string& bytes) : bytes(bytes) {}

    std::string to_bytes() const {
        return bytes;
    }

    std::string str() const {
        // Implement conversion from byte representation to string representation
        // Assuming the byte representation is in a specific format
        // Implement the conversion logic based on the given format
        // Return the string representation of the decimal number
        // Example implementation:
        // ...
    }

    static Decimal from_bytes(const std::string& bytes) {
        // Implement conversion from byte representation to Decimal object
        // Create and return a Decimal object using the provided byte representation
        return Decimal(bytes);
    }

    static Decimal from_str(const std::string& str) {
        // Implement conversion from string representation to Decimal object
        // Validate the input string for a valid decimal number format
        // If the input is valid, create and return a Decimal object using the provided string representation
        // If the input is invalid, throw an exception
        // Example implementation:
        // ...
    }
};

int main() {
    // Test cases
    try {
        std::string byteRep1 = "\x02\x12\x34\x56\x70\x0d";
        std::string byteRep2 = "\x02\x12\x34\x56\x11\xd0";
        std::string byteRep3 = "\x02\x12\x34\x56\x72\x0c";
        std::string byteRep4 = "\x02\x12\x34\x56\x34\xc0";

        std::cout << Decimal::from_bytes(byteRep1).str() << std::endl;  // Expected: "-1234567.00"
        std::cout << Decimal::from_bytes(byteRep2).str() << std::endl;  // Expected: "-123456.11"
        std::cout << Decimal::from_bytes(byteRep3).str() << std::endl;  // Expected: "1234567.20"
        std::cout << Decimal::from_bytes(byteRep4).str() << std::endl;  // Expected: "123456.34"

        Decimal::from_str("bla");     // Expected: Throw an exception
        Decimal::from_str("042423x");  // Expected: Throw an exception
        Decimal::from_str("--042423"); // Expected: Throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
