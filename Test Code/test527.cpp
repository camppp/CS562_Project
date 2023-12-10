class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int p = l + (r - l) / 2;
            if (nums[p] == target) return p;
            if (target < nums[p]) r = p - 1;
            else l = p + 1;
        }
        return -1;
    }
};
