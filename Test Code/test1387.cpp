#include <iostream>
#include <cmath>

// Function to calculate the conversion error when converting an integer to a floating-point number
static float calculateFloatConversionError(int srcBits) {
    if (srcBits > 0) {
        // Clamp the number of bits to a valid range (0 to 32)
        const int clampedBits = std::clamp<int>(srcBits, 0, 32);

        // Calculate the maximum value that can be represented by the integer with the given number of bits
        const float srcMaxValue = std::max((float)(1ULL << clampedBits) - 1.0f, 1.0f);

        // Calculate the conversion error as the reciprocal of the maximum value
        const float error = 1.0f / srcMaxValue;

        // Clamp the error to ensure it falls within the range [0.0, 1.0]
        return std::clamp<float>(error, 0.0f, 1.0f);
    } else {
        // Handle the case where srcBits is not a positive integer
        std::cerr << "Error: srcBits must be a positive integer." << std::endl;
        return 0.0f;  // Return a default error value
    }
}

int main() {
    // Test the calculateFloatConversionError function
    int bits = 8;  // Number of bits used to represent the integer
    float conversionError = calculateFloatConversionError(bits);
    std::cout << "Conversion error for " << bits << " bits: " << conversionError << std::endl;

    return 0;
}
