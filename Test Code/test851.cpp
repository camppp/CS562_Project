#include <iostream>
#include <vector>

int shifted_binary_search(const std::vector<int>& vec, int n, int l, int h) {
    if (l > h) {
        std::cout << "Element " << n << " not found within indices [" << l << ", " << h << "]." << std::endl;
        return -1;
    }

    int mid = (l + h) / 2;
    if (vec[mid] == n) {
        std::cout << "Element " << n << " found at index " << mid << "." << std::endl;
        return mid;
    }

    if (vec[l] <= vec[mid]) {
        if (n >= vec[l] && n < vec[mid]) {
            std::cout << "Assuming search in the lower range indices [" << l << ", " << mid - 1 << "]." << std::endl;
            return shifted_binary_search(vec, n, l, mid - 1);
        } else {
            std::cout << "Assuming search in the higher range indices [" << mid + 1 << ", " << h << "]." << std::endl;
            return shifted_binary_search(vec, n, mid + 1, h);
        }
    } else {
        if (n > vec[mid] && n <= vec[h]) {
            std::cout << "Assuming search in the higher range indices [" << mid + 1 << ", " << h << "]." << std::endl;
            return shifted_binary_search(vec, n, mid + 1, h);
        } else {
            std::cout << "Assuming search in the lower range indices [" << l << ", " << mid - 1 << "]." << std::endl;
            return shifted_binary_search(vec, n, l, mid - 1);
        }
    }
}

int main() {
    std::vector<int> vec = {6, 7, 8, 9, 10, 1, 2, 3, 4, 5};
    int index = shifted_binary_search(vec, 3, 0, vec.size() - 1);
    if (index != -1) {
        std::cout << "Element found at index: " << index << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    return 0;
}
