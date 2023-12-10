int maxScore(vector<int>& nums) {
    int n = nums.size();
    int dp[n+1];
    dp[0] = 0;
    dp[1] = nums[0];
    dp[n] = nums[n-1];
    for (int i = 1; i < n-1; i++) {
        dp[i] = max(dp[i-1], dp[i+1]) + nums[i];
    }
    return dp[0];
}
