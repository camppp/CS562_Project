#include <iostream>

bool isPowerOfTwo(int number) {
    if (number <= 0) {
        return false;  // 0 and negative numbers are not powers of two
    }
    return (number & (number - 1)) == 0;  // A power of two has only one bit set in its binary representation
}

int main() {
    int input;
    std::cout << "Enter a positive integer: ";
    std::cin >> input;

    if (isPowerOfTwo(input)) {
        std::cout << "The given number is a power of two" << std::endl;
    } else {
        std::cout << "The given number is not a power of two" << std::endl;
    }

    return 0;
}
