#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minOperations(string s) {
    string DB[6] = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    int dp[7001][6] = {0};

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < s.size(); j++) {
            dp[j + 1][i] = dp[j][i] + (s[j] != DB[i][j]);
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < 6; i++) {
        res = min(res, dp[s.size()][i]);
    }

    return res;
}

int main() {
    string s = "ACB";
    cout << minOperations(s) << endl;  // Output: 1
    return 0;
}
