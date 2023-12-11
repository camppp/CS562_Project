class Rational {
public:
    Rational(int numerator, int denominator) {
        // Check for division by zero
        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }

        // Reduce the fraction to its lowest terms
        int gcd = gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Store the numerator and denominator
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Overloaded operators
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
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Rational& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const {
        return numerator != other.numerator || denominator != other.denominator;
    }

    // Method to convert to double
    double to_double() const {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;

    // Helper function to find the greatest common divisor
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
