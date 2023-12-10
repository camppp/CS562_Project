long long maxSumSubarray2D(int n, int m, int a[n][m]) {
    long long maxSum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    sum += a[k][l];
                }
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
