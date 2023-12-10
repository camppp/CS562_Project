int findFirstPositive(int arr[], int n) {
    int p = 0;
    while (p < n) {
        if (arr[p] > 0) {
            return p;
        }
        p++;
    }
    return -1;
}
