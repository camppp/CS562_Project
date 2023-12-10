int findFirstPositive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return i;
        }
    }
    return -1;
}
