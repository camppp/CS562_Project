int findSmallestIndex(int arr[], int size) {
    int smallest = arr[0];
    int smallestIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            smallestIndex = i;
        }
    }

    return smallestIndex;
}
