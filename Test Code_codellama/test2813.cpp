#include <iostream>
#include <cmath>

int64_t minCost(int64_t a, int64_t b, int64_t k, int64_t l) {
    int64_t cost1 = k % l * a + k / l * b;
    int64_t cost2 = k / l * b + b;
    return std::min(cost1, cost2);
}

int main() {
    int64_t a, b, k, l;
    std::cin >> a >> b >> k >> l;
    std::cout << minCost(a, b, k, l) << std::endl;
    return 0;
}
