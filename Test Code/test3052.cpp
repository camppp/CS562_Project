#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumPath(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the first row and column with the values from the matrix
    for (int i = 0; i < n; i++) {
        dp[0][i] = matrix[0][i];
    }
    for (int i = 0; i < n; i++) {
        dp[i][0] = matrix[i][0];
    }

    // Compute the minimum sum path from the top-left to the bottom-right
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }

    // Return the minimum sum
    return dp[n - 1][n - 1];
}

int main() {
    vector<vector<int>> matrix = {
        {3, 1, 2},
        {4, 3, 1},
        {5, 6, 1}
    };
    cout << minSumPath(matrix) << endl;
    return 0;
}
