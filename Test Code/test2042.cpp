#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSearchCost(vector<int> keys, vector<int> freq) {
    // Calculate the sum of the frequencies of each key
    int sum = 0;
    for (int i = 0; i < keys.size(); i++) {
        sum += freq[i];
    }

    // Initialize the minimum search cost to infinity
    int minCost = INT_MAX;

    // Iterate over all possible root nodes
    for (int i = 0; i < keys.size(); i++) {
        // Calculate the search cost for the current root node
        int cost = 0;
        for (int j = 0; j < keys.size(); j++) {
            if (j != i) {
                cost += freq[j] * abs(keys[i] - keys[j]);
            }
        }

        // Update the minimum search cost if the current cost is less than the previous minimum
        if (cost < minCost) {
            minCost = cost;
        }
    }

    return minCost;
}

int main() {
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    int minCost = minSearchCost(keys, freq);
    cout << "Minimum search cost: " << minCost << endl;
    return 0;
}
