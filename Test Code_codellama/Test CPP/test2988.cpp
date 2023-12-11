#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack(int n, int W, vector<int> w, vector<int> v) {
    // Sort the items based on their value-to-weight ratio
    sort(w.begin(), w.end(), [](int a, int b) { return a / b; });
    sort(v.begin(), v.end(), [](int a, int b) { return a / b; });

    // Initialize the maximum value and the total weight
    int max_value = 0;
    int total_weight = 0;

    // Iterate through the items and select the ones that fit in the knapsack
    for (int i = 0; i < n; i++) {
        // If the current item fits in the knapsack, add it to the selection
        if (total_weight + w[i] <= W) {
            max_value += v[i];
            total_weight += w[i];
        }
        // If the current item does not fit in the knapsack, break it into fractions
        else {
            int fraction = (W - total_weight) / w[i];
            max_value += v[i] * fraction;
            total_weight += w[i] * fraction;
            break;
        }
    }

    return max_value;
}

int main() {
    int n = 5;
    int W = 10;
    vector<int> w = {2, 3, 4, 5, 6};
    vector<int> v = {10, 20, 30, 40, 50};

    int max_value = knapsack(n, W, w, v);

    cout << "Maximum value: " << max_value << endl;

    return 0;
}
