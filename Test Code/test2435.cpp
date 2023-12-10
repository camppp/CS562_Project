#include <iostream>

void generatePattern(int N) {
    if (N % 2 == 0) {
        std::cout << "E" << '\n';
    } else {
        std::cout << "O" << '\n';
    }
}

int main() {
    int input;
    std::cout << "Enter an integer: ";
    std::cin >> input;
    generatePattern(input);
    return 0;
}
