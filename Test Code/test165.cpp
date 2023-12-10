#include <vector>
#include <algorithm>

double findMedian(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());  // Sort the vector in ascending order

    int n = nums.size();
    if (n % 2 == 0) {
        // If the number of elements is even, return the average of the two middle numbers
        return (static_cast<double>(nums[n / 2 - 1]) + static_cast<double>(nums[n / 2])) / 2.0;
    } else {
        // If the number of elements is odd, return the middle number
        return static_cast<double>(nums[n / 2]);
    }
}
