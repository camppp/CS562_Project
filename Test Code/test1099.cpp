#include <iostream>
#include <vector>
#include <algorithm>

class ClosestNumber {
private:
    std::vector<int> options;

public:
    ClosestNumber(std::vector<int> opt) : options(opt) {
        std::sort(options.begin(), options.end());
    }

    int closest(int c) {
        int op1 = *std::lower_bound(options.begin(), options.end(), c);
        int op2 = *std::prev(std::upper_bound(options.begin(), options.end(), c));

        if (std::abs(op1 - c) < std::abs(op2 - c))
            return op1;
        return op2;
    }
};

int main() {
    std::vector<int> options = {1, 3, 5, 7, 9};
    ClosestNumber cn(options);
    std::cout << cn.closest(6) << std::endl;  // Output: 5
    std::cout << cn.closest(8) << std::endl;  // Output: 7
    return 0;
}
