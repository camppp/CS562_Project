#include <iostream>

// Function to calculate the greatest common divisor (GCD) using Euclidean algorithm
int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

// Function to calculate the least common multiple (LCM) using the GCD
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}

int main() {
    // Test cases
    std::cout << "GCD of 12 and 18: " << gcd(12, 18) << std::endl; // Output: 6
    std::cout << "LCM of 12 and 18: " << lcm(12, 18) << std::endl; // Output: 36

    std::cout << "GCD of 15 and 25: " << gcd(15, 25) << std::endl; // Output: 5
    std::cout << "LCM of 15 and 25: " << lcm(15, 25) << std::endl; // Output: 75

    std::cout << "GCD of 17 and 31: " << gcd(17, 31) << std::endl; // Output: 1
    std::cout << "LCM of 17 and 31: " << lcm(17, 31) << std::endl; // Output: 527

    return 0;
}
