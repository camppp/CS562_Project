#include <iostream>
#include <vector>

using namespace std;

int longestCommonSubsequence(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    vector<int> A = {1, 2, 3, 4, 1};
    vector<int> B = {3, 4, 1, 2, 1, 3};
    int result = longestCommonSubsequence(A, B);
    cout << "The longest common subsequence has length " << result << "." << endl;
    return 0;
}
