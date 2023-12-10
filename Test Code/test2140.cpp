#include <iostream>
#include <iomanip>
#include <string>
#include <bitset>

std::string positBinaryRepresentation(int nbits, int es, double value) {
    // Calculate the maximum and minimum values for the posit representation
    double maxVal = (1 << (nbits - 1)) * (1 + (1 << es));
    double minVal = -maxVal;

    // Check if the value is within the representable range
    if (value > maxVal || value < minVal) {
        throw "Value out of range for the given posit configuration";
    }

    // Calculate the binary representation of the posit value
    int intPart = static_cast<int>(value);
    double fracPart = value - intPart;
    std::string binaryInt = std::bitset<nbits>(intPart).to_string();
    std::string binaryFrac = "";
    if (fracPart != 0) {
        binaryFrac += ".";
        while (fracPart != 0) {
            fracPart *= 2;
            int bit = static_cast<int>(fracPart);
            binaryFrac += std::to_string(bit);
            fracPart -= bit;
        }
    }

    return binaryInt + binaryFrac;
}
