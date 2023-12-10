#include <iostream>
#include <vector>

using namespace std;

bool subsetSumExists(vector<int> wt, int Sum) {
    int n = wt.size();
    bool dp[n+1][Sum+1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=Sum; j++) {
            if (wt[i-1] <= j) {
                dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][Sum];
}

int main() {
    vector<int> wt = {3, 34, 4, 12, 5, 2};
    int Sum = 9;
    bool exists = subsetSumExists(wt, Sum);
    cout << "Does a subset of the items exist with a weight sum of " << Sum << "? " << exists << endl;
    return 0;
}
