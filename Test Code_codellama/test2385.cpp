c
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
        
        last = m;
    }
    
    // did not make any progress
    if (l - 1 <= last) {
        return 0;
    }
    
    last = l - 1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = binarySearch(arr, n, target);
    printf("Result: %d\n", result);
    return 0;
}
