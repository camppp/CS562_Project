#include <iostream>
#include <unordered_map>
#include <vector>

int countPairsWithSum(const std::vector<int>& arr, int target) {
    std::unordered_map<int, int> map;
    int count = 0;

    for (int i = 0; i < arr.size(); i++) {
        int complement = target - arr[i];
        if (map.find(complement) != map.end()) {
            count += map[complement];
        }
        map[arr[i]]++;
    }

    return count;
}
