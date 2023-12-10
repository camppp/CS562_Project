#include <iostream>

double Calculate(double num1, double num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                std::cerr << "Error: Division by zero" << std::endl;
                return 0;  // Return 0 for division by zero
            }
        default:
            std::cerr << "Error: Invalid operator" << std::endl;
            return 0;  // Return 0 for invalid operator
    }
}

int main() {
    // Test cases
    std::cout << Calculate(2, 3, '+') << std::endl;  // Output: 5.0
    std::cout << Calculate(5, 2, '-') << std::endl;  // Output: 3.0
    std::cout << Calculate(4, 2, '*') << std::endl;  // Output: 8.0
    std::cout << Calculate(6, 3, '/') << std::endl;  // Output: 2.0
    std::cout << Calculate(8, 0, '/') << std::endl;  // Output: Error: Division by zero, 0.0
    std::cout << Calculate(4, 3, '%') << std::endl;  // Output: Error: Invalid operator, 0.0
    return 0;
}
