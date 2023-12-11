vector<vector<int>> findUniqueCombinations(vector<int>& nums, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num == target) {
            combinations.push_back(combination);
            return combinations;
        }
        combination.push_back(num);
        findUniqueCombinations(nums, target - num, combination);
        combination.pop_back();
    }
    return combinations;
}
