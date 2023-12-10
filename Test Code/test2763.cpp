#include <string>
#include <algorithm>

class Solution {
public:
    bool CheckPermutation(std::string s1, std::string s2) {
        if (s1.length() != s2.length()) {
            return false;  // If the lengths are different, they cannot be permutations
        }

        std::sort(s1.begin(), s1.end());  // Sort the characters in s1
        std::sort(s2.begin(), s2.end());  // Sort the characters in s2

        return s1 == s2;  // Return true if the sorted strings are equal, indicating a permutation
    }
};
