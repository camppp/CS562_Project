#include <iostream>

int get_user_input() {
    int input;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> input;
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a non-negative integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return get_user_input();
    }
    return input;
}

int factorial(int n) {
    if (n < 0) {
        std::cout << "Invalid input. Please enter a non-negative integer: ";
        return get_user_input();
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = get_user_input();
    std::cout << "The factorial of " << n << " is " << factorial(n) << std::endl;
    return 0;
}
