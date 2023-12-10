#include <iostream>
#include <vector>

class Polynomial {
public:
    Polynomial(const std::vector<int>& coefficients) : coefficients_(coefficients) {}

    Polynomial operator+(const Polynomial& other) const {
        std::vector<int> result;
        for (int i = 0; i < coefficients_.size(); i++) {
            result.push_back(coefficients_[i] + other.coefficients_[i]);
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<int> result;
        for (int i = 0; i < coefficients_.size(); i++) {
            result.push_back(coefficients_[i] - other.coefficients_[i]);
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result;
        for (int i = 0; i < coefficients_.size(); i++) {
            for (int j = 0; j < other.coefficients_.size(); j++) {
                result.push_back(coefficients_[i] * other.coefficients_[j]);
            }
        }
        return Polynomial(result);
    }

    int evaluate(int x) const {
        int result = 0;
        for (int i = 0; i < coefficients_.size(); i++) {
            result += coefficients_[i] * std::pow(x, i);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        os << "Polynomial(";
        for (int i = 0; i < p.coefficients_.size(); i++) {
            os << p.coefficients_[i];
            if (i < p.coefficients_.size() - 1) {
                os << " + ";
            }
        }
        os << ")";
        return os;
    }

private:
    std::vector<int> coefficients_;
};
