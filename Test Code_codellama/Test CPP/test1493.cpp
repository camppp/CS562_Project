c
int findSmallestIndex(int arr[], int size) {
    smallestIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}
