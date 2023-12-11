c
int maxSubarraySum(int arr[], int size) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < size; i++) {
        currentSum += arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}
