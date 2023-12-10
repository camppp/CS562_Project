#include <iostream>

unsigned long long calculateModulo(unsigned long long limit) {
    return limit % modulo;
}

int main() {
    unsigned long long limit;
    std::cin >> limit;
    std::cout << calculateModulo(limit) << std::endl;
    return 0;
}
