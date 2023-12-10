#include <iostream>

// Variadic template function to calculate the sum of all arguments
template<typename T>
T sum(T val) {
    return val;  // Base case: return the single argument
}

template<typename T, typename... Types>
T sum(T firstArg, Types... args) {
    return firstArg + sum(args...);  // Recursively sum the arguments
}

int main() {
    // Test cases
    std::cout << sum(1, 2, 3, 4, 5) << std::endl;  // Output: 15
    std::cout << sum(3.14, 2.71, 1.618) << std::endl;  // Output: 7.468
    std::cout << sum(10) << std::endl;  // Output: 10
    std::cout << sum() << std::endl;  // Output: 0 (no arguments)
    return 0;
}
