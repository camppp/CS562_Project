#include <iostream>
#include <vector>

class Solution {
public:
    int findAnswer(std::vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            ans += num;
        }
        return ans;
    }
};
