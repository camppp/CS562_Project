#include <iostream>
#include <vector>

std::vector<int> captureElements(std::vector<int> arr, int num) {
    if (arr.empty() || num == 0) {
        return {};
    }

    std::vector<int> result;
    for (int i = 0; i < num; i++) {
        result.push_back(arr[i]);
    }

    return result;
}
