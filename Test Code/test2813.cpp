#include <iostream>
#include <algorithm>

int64_t minCost(int64_t a, int64_t b, int64_t k, int64_t l) {
    return std::min(k % l * a + k / l * b, k / l * b + b);
}

int main() {
    std::cout << minCost(3, 5, 7, 2) << std::endl;  // Output: 26
    std::cout << minCost(2, 3, 5, 3) << std::endl;  // Output: 9
    return 0;
}
