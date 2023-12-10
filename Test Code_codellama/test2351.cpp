#include <iostream>
#include <vector>

using namespace std;

int maxWeightAfterConnectingRopes(vector<int> weight, int rope, int n) {
    int maxWeight = 0;
    for (int i = 0; i < rope; i++) {
        maxWeight += weight[i] * n;
    }
    return maxWeight;
}

int main() {
    vector<int> weight = {4, 3, 2, 6};
    int rope = 4;
    int n = 1;
    int maxWeight = maxWeightAfterConnectingRopes(weight, rope, n);
    cout << "Maximum weight: " << maxWeight << endl;
    return 0;
}
