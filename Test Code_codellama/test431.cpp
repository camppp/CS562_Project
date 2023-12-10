#include <iostream>
#include <cmath>

class FractionalMultiplier {
public:
    FractionalMultiplier(int numDigits) {
        this->numDigits = numDigits;
    }

    int[] multiply(int[] fraction1, int[] fraction2) {
        int numerator = fraction1[0] * fraction2[0];
        int denominator = fraction1[1] * fraction2[1];

        // Reduce the fraction
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Check if the result is an integer
        if (denominator == 1) {
            return {numerator, 1};
        }

        // Return the result as a reduced fraction
        return {numerator, denominator};
    }

private:
    int numDigits;
};
