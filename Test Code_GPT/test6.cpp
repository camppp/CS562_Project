#include <vector>
#include <climits>

int minCoins(std::vector<int>& coins, int amount) {
    // Create a vector to store the minimum number of coins for each amount
    std::vector<int> dp(amount + 1, INT_MAX);

    // Base case: 0 coins needed to make up amount 0
    dp[0] = 0;

    // Iterate through each coin denomination
    for (int coin : coins) {
        // Update the minimum number of coins for each amount
        for (int i = coin; i <= amount; ++i) {
            if (dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Check if the amount is achievable and return the result
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    // Example usage
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = minCoins(coins, amount);

    if (result != -1) {
        std::cout << "Minimum number of coins needed: " << result << std::endl;
    } else {
        std::cout << "It is not possible to make up the amount with the given coins." << std::endl;
    }

    return 0;
}
