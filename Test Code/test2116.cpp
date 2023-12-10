int binarySearch(int data[], int size, int key) {
    int min = 0;
    int max = size - 1;
    
    while (min <= max) {
        int mid = min + (max - min) / 2; // calculate the midpoint for roughly equal partition
        
        if (data[mid] == key) {
            return mid; // key found at index mid
        } else if (data[mid] < key) {
            min = mid + 1; // key is in the upper half
        } else {
            max = mid - 1; // key is in the lower half
        }
    }
    
    return -1; // key not found
}
