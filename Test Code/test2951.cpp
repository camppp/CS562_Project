#include <iostream>

int qRound(double value) {
    return static_cast<int>(value + 0.5);
}

int main() {
    double valueA = 1.6;
    double valueB = 2.8;

    int roundedValueA = qRound(valueA);
    int roundedValueB = qRound(valueB);

    std::cout << "Rounded value of " << valueA << ": " << roundedValueA << std::endl;
    std::cout << "Rounded value of " << valueB << ": " << roundedValueB << std::endl;

    return 0;
}
