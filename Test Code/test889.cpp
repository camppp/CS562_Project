int findMax(int arr[], int size) {
    int max = arr[0];  // Initialize max with the first element of the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Update max if a larger element is found
        }
    }
    return max;  // Return the maximum value found in the array
}
