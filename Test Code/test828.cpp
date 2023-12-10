#include <iostream>

unsigned int calculateRemainder(unsigned int k, unsigned int test) {
    return test % k;
}

int main() {
    unsigned int k = 5;
    unsigned int test = 453;
    unsigned int remainder = calculateRemainder(k, test);
    std::cout << "The remainder when " << test << " is divided by " << k << " is " << remainder << std::endl;
    return 0;
}
