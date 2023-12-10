vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> combinations;
    vector<int> combination;
    combinationSumHelper(candidates, target, combination, combinations);
    return combinations;
}

void combinationSumHelper(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& combinations) {
    if (target == 0) {
        combinations.push_back(combination);
        return;
    }
    for (int i = 0; i < candidates.size(); i++) {
        if (candidates[i] <= target) {
            combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], combination, combinations);
            combination.pop_back();
        }
    }
}
