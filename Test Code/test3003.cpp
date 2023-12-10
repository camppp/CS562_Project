class Solution {
public:
    int jump(vector<int> &nums) {
        int result = 0, cover = 0, maxcover = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            maxcover = max(maxcover, i + nums[i]);
            if (i == cover) {
                result++;
                cover = maxcover;
            }
        }
        return result;
    }
};
