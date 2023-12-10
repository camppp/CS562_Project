int knapsackMaxValue(int W, int w[], int p[]) {
    int ans[W+1][n+1];
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= n; j++) {
            if (i < 0 || j < 0) {
                ans[i][j] = 0;
            } else if (i >= w[j]) {
                ans[i][j] = max(ans[i-w[j]][j-1] + p[j], ans[i][j-1]);
            } else {
                ans[i][j] = ans[i][j-1];
            }
        }
    }
    return ans[W][n];
}
