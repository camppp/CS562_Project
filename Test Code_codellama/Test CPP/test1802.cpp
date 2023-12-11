#include <iostream>
#include <vector>

using namespace std;

int longestConsecutiveNonNegative(vector<int> nums) {
    int maxLength = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            int currentLength = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == nums[i] + currentLength) {
                    currentLength++;
                } else {
                    break;
                }
            }
            maxLength = max(maxLength, currentLength);
        }
    }
    return maxLength;
}

int main() {
    vector<int> nums = {1, -2, 3, 4, 5, -1, 0, 7, 8};
    cout << longestConsecutiveNonNegative(nums) << endl;
    return 0;
}
