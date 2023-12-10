#include <cmath>

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }

        int sum = 1; // Start with 1 as all numbers are divisible by 1

        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                sum += i;
                if (i != num / i) {
                    sum += num / i;
                }
            }
        }

        return sum == num;
    }
};

// Example usage:
#include <iostream>

int main() {
    Solution solution;
    int num = 28;

    if (solution.checkPerfectNumber(num)) {
        std::cout << num << " is a perfect number." << std::endl;
    } else {
        std::cout << num << " is not a perfect number." << std::endl;
    }

    return 0;
}
