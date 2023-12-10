#include <iostream>

void generatePattern(int n) {
    if (n % 2 == 0) {
        std::cout << "E";
    } else {
        std::cout << "O";
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    generatePattern(n);
    return 0;
}
