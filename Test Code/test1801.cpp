#include <iostream>

void fill() {
    // Function to initialize variables (not relevant to the problem)
}

unsigned int modulo = 100000000;

unsigned long long calculateModulo(unsigned long long limit) {
    return limit % modulo;
}

int main() {
    unsigned long long limit;
    std::cin >> limit;
    std::cout << calculateModulo(limit) << std::endl;
    return 0;
}
