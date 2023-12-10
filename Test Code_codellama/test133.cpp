#include <iostream>

int main() {
    int len;
    std::cout << "Enter the value of len: ";
    std::cin >> len;

    if (len == 1) {
        std::cout << "A";
    } else if (len == 2) {
        std::cout << "A\nBB";
    } else if (len == 3) {
        std::cout << "A\nBB\nCCC";
    } else if (len == 4) {
        std::cout << "A\nBB\nCCC\nDDDD";
    } else {
        std::cout << "Invalid value of len";
    }

    return 0;
}
