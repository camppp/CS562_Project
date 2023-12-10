#include <iostream>
using namespace std;

int maxTotalWeight(int weights[], int n, int w) {
    bool dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = false;
            else if (weights[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - weights[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int res = 0;
    for (int j = w; j >= 0; j--) {
        if (dp[n][j]) {
            res = j;
            break;
        }
    }
    return res;
}

int main() {
    int weights[] = {3, 7, 2, 8, 4};
    int n = 5;
    int w = 10;
    cout << maxTotalWeight(weights, n, w) << endl;  // Output: 14
    return 0;
}
