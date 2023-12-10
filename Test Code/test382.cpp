#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double re, double im) : real(re), imag(im) {}

    // Addition operator overloading
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction operator overloading
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication operator overloading
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Division operator overloading
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
    }

    // Output stream insertion operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i";
        return os;
    }

    // Method to calculate the magnitude of the complex number
    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }
};

int main() {
    Complex a;
    Complex b(8, 0);
    Complex c(0, -4);
    Complex d(29.99, 88.44);

    std::cout << "Complex number a: " << a << std::endl;
    std::cout << "Complex number b: " << b << std::endl;
    std::cout << "Complex number c: " << c << std::endl;
    std::cout << "Complex number d: " << d << std::endl;

    Complex sum = b + c;
    Complex difference = b - c;
    Complex product = b * c;
    Complex quotient = b / c;

    std::cout << "Sum of b and c: " << sum << std::endl;
    std::cout << "Difference of b and c: " << difference << std::endl;
    std::cout << "Product of b and c: " << product << std::endl;
    std::cout << "Quotient of b and c: " << quotient << std::endl;

    std::cout << "Magnitude of b: " << b.magnitude() << std::endl;

    return 0;
}
