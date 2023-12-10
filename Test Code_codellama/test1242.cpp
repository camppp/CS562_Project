int uniquePaths(int m, int n, vector<vector<int>>& obstacleGrid) {
    // Initialize the dp array with the starting values
    vector<vector<int>> dp(m, vector<int>(n, 1));

    // Loop through the grid and update the dp array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    // Return the final value in the dp array
    return dp[m-1][n-1];
}
