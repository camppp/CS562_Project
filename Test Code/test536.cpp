#include <iostream>
#include <vector>

class Polynomial {
private:
    std::vector<int> coefficients;

public:
    Polynomial(const std::vector<int>& coeffs) : coefficients(coeffs) {}

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> resultCoeffs(maxSize, 0);

        for (size_t i = 0; i < coefficients.size(); ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            resultCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = std::max(coefficients.size(), other.coefficients.size());
        std::vector<int> resultCoeffs(maxSize, 0);

        for (size_t i = 0; i < coefficients.size(); ++i) {
            resultCoeffs[i] += coefficients[i];
        }

        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            resultCoeffs[i] -= other.coefficients[i];
        }

        return Polynomial(resultCoeffs);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0);

        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(resultCoeffs);
    }

    int evaluate(int x) const {
        int result = 0;
        int power = 1;

        for (int coeff : coefficients) {
            result += coeff * power;
            power *= x;
        }

        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            if (p.coefficients[i] != 0) {
                if (i < p.coefficients.size() - 1) {
                    os << (p.coefficients[i] > 0 ? " + " : " - ");
                }
                if (i > 0) {
                    os << std::abs(p.coefficients[i]) << "x^" << i;
                } else {
                    os << std::abs(p.coefficients[i]);
                }
            }
        }
        return os;
    }
};

int main() {
    Polynomial p1({3, 2, -5});
    Polynomial p2({-1, 4, 2});

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    Polynomial sum = p1 + p2;
    std::cout << "Sum: " << sum << std::endl;

    Polynomial difference = p1 - p2;
    std::cout << "Difference: " << difference << std::endl;

    Polynomial product = p1 * p2;
    std::cout << "Product: " << product << std::endl;

    int x = 2;
    std::cout << "p1 evaluated at x=" << x << ": " << p1.evaluate(x) << std::endl;
    std::cout << "p2 evaluated at x=" << x << ": " << p2.evaluate(x) << std::endl;

    return 0;
}
