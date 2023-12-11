#include <string>

class StringManipulator {
public:
    std::string reverseString(std::string s) {
        std::string reversedString;
        for (int i = s.length() - 1; i >= 0; i--) {
            reversedString += s[i];
        }
        return reversedString;
    }
};
