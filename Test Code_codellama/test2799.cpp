#include <iostream>
#include <string>

int main() {
    // Prompt the user to input an operation and two values
    std::cout << "Enter an operation (+, -, *, /): ";
    std::string operation;
    std::cin >> operation;

    std::cout << "Enter the first value: ";
    int value1;
    std::cin >> value1;

    std::cout << "Enter the second value: ";
    int value2;
    std::cin >> value2;

    // Perform the specified operation on the two values
    int result = 0;
    if (operation == "+" || operation == "+") {
        result = value1 + value2;
    } else if (operation == "-" || operation == "-") {
        result = value1 - value2;
    } else if (operation == "*" || operation == "*") {
        result = value1 * value2;
    } else if (operation == "/" || operation == "/") {
        result = value1 / value2;
    } else {
        std::cout << "Invalid operation. Please try again." << std::endl;
        return 1;
    }

    // Output the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}
