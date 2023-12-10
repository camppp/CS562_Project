#include <vector>
#include <algorithm>

void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& combination, std::vector<int>& candidates, int target, int start) {
    if (target < 0) return;
    if (target == 0) {
        res.push_back(combination);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        combination.push_back(candidates[i]);
        backtrack(res, combination, candidates, target - candidates[i], i + 1);
        combination.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> combination;
    backtrack(res, combination, candidates, target, 0);
    return res;
}
