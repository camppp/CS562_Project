#include <iostream>
#include <vector>

int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the number of nodes: ";
    std::cin >> n;
    std::cout << "Number of unique binary search trees with " << n << " nodes: " << numTrees(n) << std::endl;
    return 0;
}
