// math_operations.h
namespace math_operations {
    int factorial(int n);
}

// math_operations.cpp
#include "math_operations.h"

int math_operations::factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// main.cpp
#include <iostream>
#include "math_operations.h"

int main() {
    int n;
    std::cout << "Enter a positive integer: ";
    std::cin >> n;

    int result = math_operations::factorial(n);
    std::cout << "The factorial of " << n << " is " << result << std::endl;

    return 0;
}
