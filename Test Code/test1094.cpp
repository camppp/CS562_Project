#include <iostream>
#include <vector>
#include <cmath>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int calculateOutput(int n, int s) {
    if (s >= 1000) {
        return 0;
    }

    // Assuming dp is a pre-calculated 2D array
    std::vector<std::vector<int>> dp(1 << 10, std::vector<int>(1001, 0));

    // Populate dp array with pre-calculated values

    int ans = 0;
    for (int i = 0; i < (1 << 10); i++) {
        if (countSetBits(i) == n) {
            ans += dp[i][s];
        }
    }

    return ans;
}

int main() {
    int n, s;
    while (std::cin >> n >> s) {
        int output = calculateOutput(n, s);
        std::cout << output << std::endl;
    }
    return 0;
}
