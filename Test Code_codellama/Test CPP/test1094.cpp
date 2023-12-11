#include <iostream>
#include <vector>

using namespace std;

int calculateOutput(int n, int s) {
    if (s >= 1000) {
        return 0;
    }

    vector<int> dp(1 << 10); // pre-calculated array

    int output = 0;
    for (int i = 0; i < (1 << 10); i++) {
        int count = __builtin_popcount(i); // count of set bits in i
        if (count == n) {
            output += dp[i];
        }
    }

    return output;
}
