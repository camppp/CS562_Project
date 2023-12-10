c++
ll mergeSort(int *arr, int l, int r) {
    if (r > l) {
        int m = l + (r - l) / 2;
        ll inversions = 0;
        inversions += mergeSort(arr, l, m);
        inversions += mergeSort(arr, m + 1, r);
        inversions += merge(arr, l, m, r);
        return inversions;
    }
    return 0;
}
