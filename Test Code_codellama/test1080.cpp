#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> &seq) {
    int n = seq.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        dp[i] = seq[i];
        for (int j = i + 1; j < n; j++) {
            if (seq[j] > seq[i] && seq[j] > dp[i]) {
                dp[i] = seq[j];
            }
        }
    }
    int maxSum = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }
    return maxSum;
}

int main() {
    vector<int> seq = {3, 2, 7, 10, 5, 8};
    cout << maxSum(seq) << endl;
    return 0;
}
