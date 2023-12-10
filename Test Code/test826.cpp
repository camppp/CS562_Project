#include <iostream>
#include <stdexcept>

class Rational {
public:
    int numerator;
    int denominator;

    Rational(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::runtime_error("Denominator cannot be zero");
        }
    }

    double to_double() const {
        return static_cast<double>(numerator) / denominator;
    }

    Rational operator+(const Rational& other) const {
        return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::runtime_error("Division by zero");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Rational& other) const {
        return (numerator * other.denominator == other.numerator * denominator);
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }
};

int main() {
    try {
        Rational r1(3, 4);
        Rational r2(7, 4);

        std::cout << r1 / r2 << "==" << r1.to_double() / r2.to_double() << "==" << static_cast<double>(r1.numerator) / r1.denominator / static_cast<double>(r2.numerator) / r2.denominator << '\n';
        if (r2 == Rational(14, 8)) std::cout << "equal\n";
        if (r2 != Rational(14, 8)) std::cout << "not equal\n";
        Rational(3, 0);  // this line will throw a runtime error due to division by zero

        // keep_window_open("~");  // For some Windows(tm) setups
    } catch (std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
