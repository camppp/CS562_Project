int binarySearch(int myArray[], int element) {
    int low = 0;
    int high = myArray.length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (myArray[mid] == element) {
            return mid;
        } else if (myArray[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}
