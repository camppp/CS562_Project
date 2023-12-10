#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> processResults(const std::vector<int>& reslist) {
    // Check if the input list is empty
    if (reslist.empty()) {
        return {};
    }

    // Remove any negative numbers from the list
    std::vector<int> positive_numbers;
    for (const auto& num : reslist) {
        if (num >= 0) {
            positive_numbers.push_back(num);
        }
    }

    // Sort the remaining positive numbers in ascending order
    std::sort(positive_numbers.begin(), positive_numbers.end());

    return positive_numbers;
}
