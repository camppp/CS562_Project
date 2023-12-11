#include <stdio.h>

int sumOfPositiveIntegers(int arr[], int size) {
    int ret = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            ret += arr[i];
        }
    }
    return ret;
}
