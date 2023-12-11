#include <iostream>
#include <cmath>

unsigned long long calculateCombinations(int n, int p) {
    if (n < 0 || p < 0) {
        return 0;
    }

    unsigned long long nFactorial = 1;
    unsigned long long pFactorial = 1;
    unsigned long long nMinusPFactorial = 1;

    for (int i = 1; i <= n; i++) {
        nFactorial *= i;
    }

    for (int i = 1; i <= p; i++) {
        pFactorial *= i;
    }

    for (int i = 1; i <= (n - p); i++) {
        nMinusPFactorial *= i;
    }

    return nFactorial / (pFactorial * nMinusPFactorial);
}

int main() {
    std::cout << calculateCombinations(5, 2) << std::endl; // Output: 10
    std::cout << calculateCombinations(10, 3) << std::endl; // Output: 120
    std::cout << calculateCombinations(7, 7) << std::endl; // Output: 1
    std::cout << calculateCombinations(3, 5) << std::endl; // Output: 0

    return 0;
}
