#include <iostream>
#include <cmath>

namespace {
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}

class Rational {
private:
    int numerator;
    int denominator;

public:
    Rational(int numerator, int denominator) {
        int commonFactor = gcd(abs(numerator), abs(denominator));
        this->numerator = numerator / commonFactor;
        this->denominator = denominator / commonFactor;
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    Rational add(const Rational& other) {
        int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    Rational subtract(const Rational& other) {
        int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    Rational multiply(const Rational& other) {
        int newNumerator = this->numerator * other.numerator;
        int newDenominator = this->denominator * other.denominator;
        return Rational(newNumerator, newDenominator);
    }

    Rational divide(const Rational& other) {
        int newNumerator = this->numerator * other.denominator;
        int newDenominator = this->denominator * other.numerator;
        return Rational(newNumerator, newDenominator);
    }

    void print() {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Rational r1(1, 2);
    Rational r2(3, 4);

    Rational sum = r1.add(r2);
    sum.print();  // Output: 5/4

    Rational difference = r1.subtract(r2);
    difference.print();  // Output: -1/4

    Rational product = r1.multiply(r2);
    product.print();  // Output: 3/8

    Rational quotient = r1.divide(r2);
    quotient.print();  // Output: 2/3

    return 0;
}
