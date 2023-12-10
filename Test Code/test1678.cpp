// Custom namespace for math operations
namespace math_operations {
    // Function to calculate the factorial of a given integer
    int factorial(int n) {
        if (n == 0 || n == 1) {
            return 1;
        } else {
            int result = 1;
            for (int i = 2; i <= n; i++) {
                result *= i;
            }
            return result;
        }
    }
}

// C++ program demonstrating the usage of custom namespace and function
#include <iostream>

int main() {
    using namespace math_operations;  // Using the custom namespace

    int num;
    std::cout << "Enter a number to calculate its factorial: ";
    std::cin >> num;

    int fact = factorial(num);  // Calling the factorial function from custom namespace
    std::cout << "Factorial of " << num << " is: " << fact << std::endl;

    return 0;
}
