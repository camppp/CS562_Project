int countOccurrences(int arr[], int value) {
    int count = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        if (arr[i] == value) {
            count++;
        }
    }
    return count;
}
