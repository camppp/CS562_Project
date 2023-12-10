#include <string>

class StringManipulator {
public:
    std::string reverseString(std::string s) {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
