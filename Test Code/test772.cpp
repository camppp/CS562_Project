int countPairsWithSum(const std::vector<int>& arr, int target) {
    std::unordered_map<int, int> countMap;
    int pairCount = 0;

    for (int num : arr) {
        int complement = target - num;
        if (countMap.find(complement) != countMap.end()) {
            pairCount += countMap[complement];
        }
        countMap[num]++;
    }

    return pairCount;
}
