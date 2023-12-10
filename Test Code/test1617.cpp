#include <vector>
#include <algorithm>

std::vector<int> processQueries(std::vector<Query>& queries, std::vector<int>& nums) {
    std::vector<int> result;
    for (const auto& query : queries) {
        std::vector<int> subarray(nums.begin() + query.l, nums.begin() + query.r + 1);
        std::sort(subarray.begin(), subarray.end());
        result.push_back(subarray[query.k - 1]);
    }
    return result;
}
