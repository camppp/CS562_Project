#ifndef EXAMPLE_H
#define EXAMPLE_H

/**
 * Takes an integer array and its size as input and returns the sum of all elements.
 * 
 * @param arr The input integer array
 * @param size The size of the input array
 * @return The sum of all elements in the array
 */
int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

#endif
