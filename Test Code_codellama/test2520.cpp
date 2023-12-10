#include <iostream>
#include <vector>

int longestIncreasingSubsequence(const std::vector<int>& nums) {
    std::vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}

int main() {
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << longestIncreasingSubsequence(nums) << std::endl;
    return 0;
}
