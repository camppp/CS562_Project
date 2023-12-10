#include <vector>
#include <algorithm>

int maxScore(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<std::vector<int>> memo(n, std::vector<int>(n, 0));

    // Helper function to calculate the maximum score
    auto helper = [&](const std::vector<int>& nums, int start, int end, int turn) -> int {
        if (start == end) {
            return nums[start] * turn;
        }
        if (memo[start][end] != 0) {
            return memo[start][end];
        }
        int scoreStart = nums[start] * turn + helper(nums, start + 1, end, -turn);
        int endStart = nums[end] * turn + helper(nums, start, end - 1, -turn);
        memo[start][end] = std::max(scoreStart * turn, endStart * turn) * turn;
        return memo[start][end];
    };

    return helper(nums, 0, n - 1, 1);
}
