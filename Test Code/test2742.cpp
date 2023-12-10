void fill_dp(string r, int n, vector<vector<int>>& dp) {
    // Initialize the dp array with 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp array based on the given conditions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (r[i] == 'a' && j == 0) {
                dp[i][j] = 1;
            } else if (r[i] == 'b' && j == 1) {
                dp[i][j] = 1;
            } else if (r[i] == 'c' && j == 2) {
                dp[i][j] = 1;
            } else if (r[i] == 'd' && j == 3) {
                dp[i][j] = 1;
            } else if (r[i] == 'e' && j == 4) {
                dp[i][j] = 1;
            } else if (r[i] == 'f' && j == 5) {
                dp[i][j] = 1;
            } else if (r[i] == 'g' && j == 6) {
                dp[i][j] = 1;
            } else if (r[i] == 'h' && j == 7) {
                dp[i][j] = 1;
            } else if (r[i] == 'i' && j == 8) {
                dp[i][j] = 1;
            } else if (r[i] == 'j' && j == 9) {
                dp[i][j] = 1;
            }
        }
    }
}
