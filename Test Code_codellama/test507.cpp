#include <iostream>
#include <vector>
#include <functional> // plus, minus
#include <numeric>    // accumulate

// Define the custom binary function to perform the custom operation
auto customOp = [](int a, int b) {
    if (b % 2 == 0) {
        return a + b;
    } else {
        return a - b;
    }
};

// Implement the performOperation function
int performOperation(const std::vector<int>& nums, int initialValue) {
    return std::accumulate(nums.begin(), nums.end(), initialValue, customOp);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int initialVal = 10;
    int result = performOperation(numbers, initialVal);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
