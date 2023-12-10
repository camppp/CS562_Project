#include <stdio.h>

int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < size; i++) {
        currentSum = (currentSum + arr[i] > arr[i]) ? currentSum + arr[i] : arr[i];
        maxSum = (currentSum > maxSum) ? currentSum : maxSum;
    }

    return maxSum;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Maximum sum of a subarray: %d\n", maxSubarraySum(arr, size));
    return 0;
}
