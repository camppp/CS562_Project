#include <iostream>

// Function to find the nearest power of 2 to n
int pow2_near(int n) {
    int power = 1;
    while (power * 2 <= n) {
        power *= 2;
    }
    return power;
}

int main() {
    std::cout << pow2_near(47) << std::endl;  // Output: 32
    std::cout << pow2_near(64) << std::endl;  // Output: 64
    std::cout << pow2_near(65) << std::endl;  // Output: 64
    return 0;
}
