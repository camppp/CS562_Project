#include <string>

class Solution {
public:
    int minOperations(const std::string& s) {
        int count1 = 0;  // Count of operations if the string starts with '1'
        int count0 = 0;  // Count of operations if the string starts with '0'

        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    count1++;  // Increment count1 if '0' is at an odd index
                } else {
                    count0++;  // Increment count0 if '1' is at an odd index
                }
            } else {
                if (s[i] == '1') {
                    count1++;  // Increment count1 if '1' is at an even index
                } else {
                    count0++;  // Increment count0 if '0' is at an even index
                }
            }
        }

        return std::min(count1, count0);  // Return the minimum count
    }
};
