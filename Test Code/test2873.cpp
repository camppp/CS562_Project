java
public int binarySearch(int[] myArray, int element) {
    int left = 0;
    int right = myArray.length - 1;
    int location = -1;

    while (right >= left) {
        int mid = left + (right - left) / 2;

        if (myArray[mid] == element) {
            location = mid;
            break;
        } else if (myArray[mid] > element) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return location;
}
