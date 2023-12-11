#include <iostream>
#include <vector>

int bubbleSortAndCountSwaps(std::vector<int> &arr) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                count++;
            }
        }
    }

    return count;
}
