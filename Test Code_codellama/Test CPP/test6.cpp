int minCoins(vector<int>& coins, int amount) {
    // Initialize a vector to store the number of coins needed for each amount
    vector<int> dp(amount + 1, -1);

    // Initialize the first element of the vector to 0
    dp[0] = 0;

    // Loop through the amounts from 1 to the target amount
    for (int i = 1; i <= amount; i++) {
        // Loop through the coins and find the minimum number of coins needed to make up the current amount
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Return the minimum number of coins needed to make up the target amount
    return dp[amount];
}
