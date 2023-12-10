#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Rational(double x) {
        int sign;

        if (x >= 0) {
            sign = 1;
        } else if (x < 0) {
            sign = -1;
        }

        // Reduce the fraction to its simplest form
        int gcd = gcd(numerator, denominator);
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }

    Rational add(const Rational& other) {
        // Add the numerators and denominators
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;

        // Reduce the fraction to its simplest form
        int gcd = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / gcd;
        newDenominator = newDenominator / gcd;

        return Rational(newNumerator, newDenominator);
    }

    Rational subtract(const Rational& other) {
        // Subtract the numerators and denominators
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;

        // Reduce the fraction to its simplest form
        int gcd = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / gcd;
        newDenominator = newDenominator / gcd;

        return Rational(newNumerator, newDenominator);
    }

    Rational multiply(const Rational& other) {
        // Multiply the numerators and denominators
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;

        // Reduce the fraction to its simplest form
        int gcd = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / gcd;
        newDenominator = newDenominator / gcd;

        return Rational(newNumerator, newDenominator);
    }

    Rational divide(const Rational& other) {
        // Divide the numerators and denominators
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;

        // Reduce the fraction to its simplest form
        int gcd = gcd(newNumerator, newDenominator);
        newNumerator = newNumerator / gcd;
        newDenominator = newDenominator / gcd;

        return Rational(newNumerator, newDenominator);
    }

    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    // GCD function to find the greatest common divisor of two numbers
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
