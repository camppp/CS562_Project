java
class Solution {
    public int[] findMissingAndRepeating(int[] nums) {
        int n = nums.length;
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }
        
        int rightmostSetBit = xor & -xor;
        
        int x = 0, y = 0;
        for (int num : nums) {
            if ((num & rightmostSetBit) > 0) {
                x ^= num;
            } else {
                y ^= num;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            if (x == i) {
                if (contains(nums, i)) {
                    x = i;
                    y = xor ^ i;
                    break;
                }
            }
        }
        
        return new int[]{x, y};
    }
    
    private boolean contains(int[] nums, int num) {
        for (int n : nums) {
            if (n == num) {
                return true;
            }
        }
        return false;
    }
}
