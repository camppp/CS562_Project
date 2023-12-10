#include <vector>
#include <algorithm>

double calculateMedian(const std::vector<int>& nums) {
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());
    int n = sortedNums.size();
    if (n % 2 == 0) {
        return (sortedNums[n / 2 - 1] + sortedNums[n / 2]) / 2.0;
    } else {
        return sortedNums[n / 2];
    }
}
