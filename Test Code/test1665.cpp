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
    int maxDegree = std::max(coefficients.size(), other.coefficients.size()) - 1;
    Polynomial result(maxDegree);
    for (int i = 0; i <= maxDegree; ++i) {
      double sum = (i < coefficients.size() ? coefficients[i] : 0) +
                   (i < other.coefficients.size() ? other.coefficients[i] : 0);
      result.setCoefficient(i, sum);
    }
    return result;
  }

  Polynomial operator-(const Polynomial& other) const {
    int maxDegree = std::max(coefficients.size(), other.coefficients.size()) - 1;
    Polynomial result(maxDegree);
    for (int i = 0; i <= maxDegree; ++i) {
      double diff = (i < coefficients.size() ? coefficients[i] : 0) -
                    (i < other.coefficients.size() ? other.coefficients[i] : 0);
      result.setCoefficient(i, diff);
    }
    return result;
  }

  Polynomial& operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
  }

  Polynomial& operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    int degree = poly.coefficients.size() - 1;
    for (int i = degree; i >= 0; --i) {
      if (poly.coefficients[i] != 0) {
        if (i < degree) {
          os << (poly.coefficients[i] > 0 ? " + " : " - ");
        }
        if (i > 0) {
          os << std::abs(poly.coefficients[i]) << "x^" << i;
        } else {
          os << std::abs(poly.coefficients[i]);
        }
      }
    }
    return os;
  }
};

int main() {
  Polynomial p1(3);
  p1.setCoefficient(3, 2.0);
  p1.setCoefficient(2, 1.0);
  p1.setCoefficient(0, 3.0);
  std::cout << "Test: p1 " << p1 << std::endl;

  Polynomial p2(2);
  p2.setCoefficient(2, 1.0);
  p2.setCoefficient(1, 2.0);
  p2.setCoefficient(0, 1.0);
  std::cout << "Test: p2 " << p2 << std::endl;

  Polynomial p3 = p1 + p2;
  std::cout << "Test: p1 + p2 " << p3 << std::endl;

  p3 += p3;
  std::cout << "Test: p3 += p3 " << p3 << std::endl;

  p3 -= p2;
  std::cout << "Test: p3 -= p2 " << p3 << std::endl;

  return 0;
}
