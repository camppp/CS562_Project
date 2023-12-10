#include <string>
#include <algorithm>

bool isPalindrome(const std::string& str) {
    std::string s = str;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
    return std::equal(s.begin(), s.end(), s.rbegin());
}
