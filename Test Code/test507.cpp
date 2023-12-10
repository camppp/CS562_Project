#include <iostream>
#include <vector>
#include <functional> // plus, minus
#include <numeric>    // accumulate

int performOperation(const std::vector<int>& nums, int initialValue) {
    std::function<int(int, int)> customOp = [](int acc, int val) {
        return val % 2 == 0 ? std::plus<int>()(acc, val) : std::minus<int>()(acc, val);
    };
    return std::accumulate(nums.begin(), nums.end(), initialValue, customOp);
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int initialVal = 10;
    int result = performOperation(numbers, initialVal);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
