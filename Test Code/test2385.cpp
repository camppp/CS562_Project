int binarySearch(int arr[], int n, int target) {
    int l = 0, r = n - 1;
    int last = -1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        if (arr[m] == target) {
            return 1; // target found
        } else if (arr[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
        
        // update last position
        last = m;
    }
    
    return 0; // target not found
}
