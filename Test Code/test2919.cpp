#include <iostream>
using namespace std;

bool isPath(int m, int n, char maze[10][10]) {
    bool dp[10][10] = {0};  // Initialize a boolean array to store the path information

    // Base case: the destination cell is reachable if it is not blocked and the previous cell is reachable
    dp[0][0] = (maze[0][0] == '0');

    // Fill in the dp array using dynamic programming
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == '0') {
                if (i > 0) dp[i][j] = dp[i][j] || dp[i - 1][j];  // Check if the cell above is reachable
                if (j > 0) dp[i][j] = dp[i][j] || dp[i][j - 1];  // Check if the cell to the left is reachable
            }
        }
    }

    return dp[m - 1][n - 1];  // Return the value of the bottom-right cell
}

int main() {
    int m = 4, n = 4;
    char maze[10][10]={
                    "0000",
                    "00X0",
                    "0000",
                    "0X00"
                };

    cout << (isPath(m, n, maze) ? "Path exists" : "No path exists") << endl;

    return 0;
}
