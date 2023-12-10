c
#include <iostream>
#include <cstring>

using namespace std;

// Array to store the values of dp
int dp[100];

// Function to calculate the value of sum
int go(int idx, int taken) {
    // Base case: if idx is equal to the length of the array, return 0
    if (idx == sizeof(dp)) {
        return 0;
    }

    // If the value of dp[idx] is already calculated, return it
    if (dp[idx] != -1) {
        return dp[idx];
    }

    // Calculate the value of dp[idx]
    int val = go(idx + 1, taken);
    if (taken == 1) {
        val = min(val, go(idx + 1, 0));
    }
    dp[idx] = val;
    return val;
}

int main() {
    // Initialize the array dp with -1
    memset(dp, -1, sizeof(dp));

    // Calculate the value of sum for (0, 0)
    int sum = go(0, 0);

    // Calculate the value of sum for (1, 0)
    sum = min(sum, go(1, 0));

    // Print the result in the format "Case x: y"
    cout << "Case 1: " << sum << endl;

    return 0;
}
