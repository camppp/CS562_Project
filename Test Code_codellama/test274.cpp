int minOperations(string s) {
    int n = s.length();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[0];
}
