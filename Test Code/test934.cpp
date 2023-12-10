#include <algorithm>

int calculateMedian(int arr[], int size) {
    std::sort(arr, arr + size);  // Sort the array in ascending order

    if (size % 2 == 0) {
        // If the size of the array is even, return the average of the two middle elements
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    } else {
        // If the size of the array is odd, return the middle element
        return arr[size / 2];
    }
}
