#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> prices) {
    int n = prices.size();
    vector<int> dp(n, 0);
    vector<int> dp_cooldown(n, 0);

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], prices[i] - prices[i - 1]);
        dp_cooldown[i] = max(dp_cooldown[i - 1], dp[i - 1] + prices[i] - prices[i - 1]);
    }

    return max(dp[n - 1], dp_cooldown[n - 1]);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}
