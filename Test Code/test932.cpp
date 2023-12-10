int findIndex(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the matching element
        }
    }
    return -1;  // Return -1 if the target integer is not found in the array
}
