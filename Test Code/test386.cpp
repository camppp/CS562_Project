#include <stdio.h>

int countOccurrences(int arr[], int size, int value) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5, 2, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 2;
    int occurrences = countOccurrences(arr, size, value);
    printf("The value %d occurs %d times in the array.\n", value, occurrences);
    return 0;
}
