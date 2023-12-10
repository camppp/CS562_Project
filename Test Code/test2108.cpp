#include <iostream>

int custom_floor(double x) {
    return (int)x;
}

int main() {
    double test1 = 3.14;
    double test2 = -2.5;
    double test3 = 10.0;
    
    std::cout << "custom_floor(3.14) = " << custom_floor(test1) << std::endl;  // Expected output: 3
    std::cout << "custom_floor(-2.5) = " << custom_floor(test2) << std::endl;  // Expected output: -3
    std::cout << "custom_floor(10.0) = " << custom_floor(test3) << std::endl;  // Expected output: 10
    
    return 0;
}
