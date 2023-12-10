// Addition
ZComplex operator+(const ZComplex& other) const {
    return ZComplex(re + other.re, im + other.im);
}

// Subtraction
ZComplex operator-(const ZComplex& other) const {
    return ZComplex(re - other.re, im - other.im);
}

// Multiplication
ZComplex operator*(const ZComplex& other) const {
    return ZComplex(re * other.re - im * other.im, re * other.im + im * other.re);
}

// Division
ZComplex operator/(const ZComplex& other) const {
    double denom = other.re * other.re + other.im * other.im;
    return ZComplex((re * other.re + im * other.im) / denom, (im * other.re - re * other.im) / denom);
}

// Power calculation
ZComplex pow(int n) const {
    if (n == 0) {
        return ZComplex(1, 0);
    } else if (n == 1) {
        return *this;
    } else if (n == 2) {
        return ZComplex(re * re - im * im, 2 * re * im);
    } else if (n == 3) {
        return ZComplex(re * re * re - 3 * re * im * im, 3 * re * re * im - re * im * im);
    } else {
        return ZComplex(pow(re, n) * pow(im, n), n * log(re) + n * log(im));
    }
}
