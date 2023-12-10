#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> maps;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        
        if (maps.count(diff)) {
            result.push_back(maps[diff]);
            result.push_back(i);
            return result;
        }
        
        maps[nums[i]] = i;
    }

    return result; // If no solution is found
}
