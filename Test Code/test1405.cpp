#include <stdio.h>

unsigned long long fact(int num) {
    unsigned long long factorial = 1;
    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }
    return factorial;
}

unsigned long long calculateCombinations(int n, int p) {
    if (n < 0 || p < 0 || p > n) {
        return 0; // Invalid input, return 0
    }
    unsigned long long numerator = fact(n);
    unsigned long long denominator = fact(p) * fact(n - p);
    if (denominator == 0) {
        return 0; // Avoid division by zero
    }
    return numerator / denominator;
}

int main() {
    int n = 5, p = 2;
    printf("C(%d, %d) = %llu\n", n, p, calculateCombinations(n, p));

    n = 10, p = 3;
    printf("C(%d, %d) = %llu\n", n, p, calculateCombinations(n, p));

    n = 7, p = 7;
    printf("C(%d, %d) = %llu\n", n, p, calculateCombinations(n, p));

    n = 3, p = 5;
    printf("C(%d, %d) = %llu\n", n, p, calculateCombinations(n, p));

    return 0;
}
