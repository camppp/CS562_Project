int calculateMedian(int arr[], int size) {
    // Sort the array in ascending order
    sort(arr, arr + size);

    // If the size of the array is odd, return the middle element
    if (size % 2 == 1) {
        return arr[size / 2];
    }

    // If the size of the array is even, return the average of the two middle elements
    int mid1 = arr[size / 2 - 1];
    int mid2 = arr[size / 2];
    return (mid1 + mid2) / 2;
}
