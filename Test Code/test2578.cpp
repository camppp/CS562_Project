// Complete the insertion sort algorithm
void insertionSort(int array[], int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Implement a function to find the frequency of a given element in the sorted array
int findFrequency(int array[], int length, int target) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            count++;
        } else if (array[i] > target) {
            break;  // Since the array is sorted, we can stop searching if the current element is greater than the target
        }
    }
    return count;
}
