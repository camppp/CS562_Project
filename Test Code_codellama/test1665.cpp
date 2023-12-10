#include <iostream>
#include <vector>

class Polynomial {
private:
  std::vector<double> coefficients;

public:
  Polynomial(int degree) : coefficients(degree + 1, 0) {}

  void setCoefficient(int degree, double coefficient) {
    coefficients[degree] = coefficient;
  }

  double getCoefficient(int degree) const {
    return coefficients[degree];
  }

  Polynomial operator+(const Polynomial& other) const {
    Polynomial result(coefficients.size());
    for (int i = 0; i < coefficients.size(); i++) {
      result.setCoefficient(i, coefficients[i] + other.getCoefficient(i));
    }
    return result;
  }

  Polynomial operator-(const Polynomial& other) const {
    Polynomial result(coefficients.size());
    for (int i = 0; i < coefficients.size(); i++) {
      result.setCoefficient(i, coefficients[i] - other.getCoefficient(i));
    }
    return result;
  }

  Polynomial& operator+=(const Polynomial& other) {
    for (int i = 0; i < coefficients.size(); i++) {
      coefficients[i] += other.getCoefficient(i);
    }
    return *this;
  }

  Polynomial& operator-=(const Polynomial& other) {
    for (int i = 0; i < coefficients.size(); i++) {
      coefficients[i] -= other.getCoefficient(i);
    }
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    for (int i = poly.coefficients.size() - 1; i >= 0; i--) {
      if (i == poly.coefficients.size() - 1) {
        os << poly.coefficients[i];
      } else {
        os << poly.coefficients[i] << "x^" << i;
      }
    }
    return os;
  }
};
