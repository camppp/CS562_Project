// ratio.hpp

#ifndef FBC_CPP_BASE_RATIO_HPP_
#define FBC_CPP_BASE_RATIO_HPP_

class Ratio {
public:
    Ratio(int numerator, int denominator);
    void simplify();
    double value() const;

private:
    int numerator_;
    int denominator_;
};

Ratio::Ratio(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {}

void Ratio::simplify() {
    // Find the greatest common divisor
    int a = numerator_;
    int b = denominator_;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    // Simplify the ratio
    numerator_ /= gcd;
    denominator_ /= gcd;
}

double Ratio::value() const {
    return static_cast<double>(numerator_) / denominator_;
}

int test_ratio_1() {
    Ratio r1(4, 8);
    r1.simplify();
    if (r1.value() == 0.5) {
        return 0;  // Test passed
    } else {
        return 1;  // Test failed
    }
}

int test_ratio_2() {
    Ratio r2(3, 7);
    r2.simplify();
    if (r2.value() == 3.0 / 7) {
        return 0;  // Test passed
    } else {
        return 1;  // Test failed
    }
}

#endif // FBC_CPP_BASE_RATIO_HPP_
