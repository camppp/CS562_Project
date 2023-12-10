#include <iostream>
#include <vector>

using namespace std;

int max_sum_submatrix(vector<vector<int>>& matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first row and column
    for (int i = 0; i < m; i++) {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 0; j < n; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Compute the maximum sum of each submatrix
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

    // Find the maximum sum that is less than or equal to k
    int max_sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] <= k) {
                max_sum = max(max_sum, dp[i][j]);
            }
        }
    }

    return max_sum;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    int k = 2;
    cout << max_sum_submatrix(matrix, k) << endl;
    return 0;
}
