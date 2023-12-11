#include <iostream>
#include <vector>

int shifted_binary_search(const std::vector<int>& vec, int n, int l, int h) {
    if (l > h) {
        return -1;
    }

    int mid = (l + h) / 2;
    if (vec[mid] == n) {
        std::cout << "Found " << n << " at index " << mid << std::endl;
        return mid;
    }

    if (vec[mid] < n) {
        std::cout << "Searching in right half of the array" << std::endl;
        return shifted_binary_search(vec, n, mid + 1, h);
    }

    std::cout << "Searching in left half of the array" << std::endl;
    return shifted_binary_search(vec, n, l, mid - 1);
}
