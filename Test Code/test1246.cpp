long long maxSubarraySum(int n, long long arr[]) {
    long long maxSum = arr[0];
    long long currentSum = arr[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}
