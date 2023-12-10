#include <cmath>

class ZComplex {
private:
    double real;
    double imag;

public:
    ZComplex(double real, double imag) : real(real), imag(imag) {}

    ZComplex operator+(const ZComplex& other) const {
        return ZComplex(real + other.real, imag + other.imag);
    }

    ZComplex operator-(const ZComplex& other) const {
        return ZComplex(real - other.real, imag - other.imag);
    }

    ZComplex operator*(const ZComplex& other) const {
        return ZComplex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    ZComplex operator/(const ZComplex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return ZComplex((real * other.real + imag * other.imag) / denominator, (imag * other.real - real * other.imag) / denominator);
    }

    ZComplex pow(int n) const {
        double r = std::pow(std::sqrt(real * real + imag * imag), n);
        double theta = std::atan2(imag, real);
        return ZComplex(r * std::cos(n * theta), r * std::sin(n * theta));
    }
};
