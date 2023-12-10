#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int weight;
};

double maxSumOfNonAdjacentNodes(int n, vector<vector<Edge>> tree) {
    double maxSum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            double sum = 0;
            for (int k = 1; k <= n; k++) {
                if (k == i || k == j) continue;
                sum += tree[k][i].weight + tree[k][j].weight;
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

int main() {
    int n = 5;
    vector<vector<Edge>> tree = {
        {{2, 3}, {3, 4}},
        {{1, 2}, {1, 5}},
        {{1, 3}},
        {{1, 4}},
        {{2, 5}}
    };
    cout << maxSumOfNonAdjacentNodes(n, tree) << endl;
    return 0;
}
