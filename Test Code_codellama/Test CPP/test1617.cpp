std::vector<int> processQueries(std::vector<Query>& queries, std::vector<int>& nums) {
    std::vector<int> result;
    for (const auto& query : queries) {
        int l = query.l, r = query.r, k = query.k, idx = query.idx;
        std::vector<int> subarray(nums.begin() + l, nums.begin() + r + 1);
        std::nth_element(subarray.begin(), subarray.begin() + k - 1, subarray.end());
        result.push_back(subarray[k - 1]);
    }
    return result;
}
