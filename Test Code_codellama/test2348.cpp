#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(const vector<int>& arr1, const vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 1};
    vector<int> arr2 = {3, 4, 1, 2, 1, 3};
    int result = longestCommonSubsequence(arr1, arr2);
    cout << "The longest common subsequence has a length of " << result << "." << endl;
    return 0;
}
