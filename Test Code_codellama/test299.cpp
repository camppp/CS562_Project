long long maxNonAdjacentSum(int a[], int n) {
    long long maxSum = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
