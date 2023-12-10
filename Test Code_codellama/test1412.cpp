#include <stdio.h>

int divide_and_conquer_sum(int arr[], int start, int end) {
    if (start == end) {
        return arr[start];
    } else {
        int mid = (start + end) / 2;
        int left_sum = divide_and_conquer_sum(arr, start, mid);
        int right_sum = divide_and_conquer_sum(arr, mid + 1, end);
        return left_sum + right_sum;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = divide_and_conquer_sum(arr, 0, size - 1);
    printf("Sum of array elements: %d\n", sum);
    return 0;
}
