#include <iostream>
#include <vector>
#include <string>
using namespace std;

void fillDP(vector<vector<int>>& dp, const string& r) {
    int n = r.length();

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
            if (r[i] - '0' < j || (i + 1 < n && r[i] - '0' == j) || (i == 0 && j == 0))
                continue;
            // Implement the logic to fill dp[i][j] based on the given conditions
            // Your code here
            // Example: dp[i][j] = some_value_based_on_conditions;
        }
    }
}

int main() {
    string r = "12345";
    int n = r.length();
    vector<vector<int>> dp(n, vector<int>(10, 0));
    fillDP(dp, r);

    // Output the filled dp array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
