#include <vector>
#include <algorithm>

void findUniqueCombinationsHelper(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue;  // Skip duplicates
        if (nums[i] > target) break;  // Optimization: stop if the current number is greater than the target
        current.push_back(nums[i]);
        findUniqueCombinationsHelper(nums, target - nums[i], i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> findUniqueCombinations(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    findUniqueCombinationsHelper(nums, target, 0, current, result);
    return result;
}
