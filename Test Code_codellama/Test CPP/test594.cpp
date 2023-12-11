#include <iostream>
#include <vector>
#include <algorithm>

double calculateMedian(const std::vector<int>& nums) {
    // Sort the input vector in ascending order
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    // Calculate the median
    int medianIndex = sortedNums.size() / 2;
    if (sortedNums.size() % 2 == 0) {
        // Even number of elements, calculate the average of the two middle numbers
        return (sortedNums[medianIndex - 1] + sortedNums[medianIndex]) / 2.0;
    } else {
        // Odd number of elements, the median is the middle number
        return sortedNums[medianIndex];
    }
}

int main() {
    std::vector<int> input1 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    double result1 = calculateMedian(input1);
    std::cout << "Median of input1: " << result1 << std::endl;

    std::vector<int> input2 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    double result2 = calculateMedian(input2);
    std::cout << "Median of input2: " << result2 << std::endl;

    return 0;
}
