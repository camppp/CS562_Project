#include <set>
#include <vector>
#include <climits>
using namespace std;

int max_sum_submatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    int maxSum = INT_MIN;

    for (int left = 0; left < n; ++left) {
        vector<int> sums(m, 0);
        for (int right = left; right < n; ++right) {
            for (int i = 0; i < m; ++i) {
                sums[i] += matrix[i][right];
            }

            set<int> accuSet;
            accuSet.insert(0);
            int curSum = 0, curMax = INT_MIN;
            for (int sum : sums) {
                curSum += sum;
                auto it = accuSet.lower_bound(curSum - k);
                if (it != accuSet.end()) {
                    curMax = max(curMax, curSum - *it);
                }
                accuSet.insert(curSum);
            }
            maxSum = max(maxSum, curMax);
        }
    }
    return maxSum;
}
