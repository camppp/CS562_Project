#include <iostream>
#include <cmath>

template <int Base, int Exponent>
class MathConcept {
public:
    static const int min_exponent = Exponent;
    static const int min_exponent10 = Exponent * 10;

    static int power() {
        return pow(Base, Exponent);
    }
};

int main() {
    std::cout << "Minimum exponent: " << MathConcept<2, 3>::min_exponent << std::endl;
    std::cout << "Minimum exponent base 10: " << MathConcept<2, 3>::min_exponent10 << std::endl;
    std::cout << "Power: " << MathConcept<2, 3>::power() << std::endl;

    return 0;
}
