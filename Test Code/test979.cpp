#include <string>
#include <algorithm>

std::string addStrings(std::string s1, std::string s2) {
    std::string result;
    int carry = 0;
    int i = s1.size() - 1, j = s2.size() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int a = (i >= 0) ? s1[i] - '0' : 0;
        int b = (j >= 0) ? s2[j] - '0' : 0;
        int temp = (a + b + carry);

        result.push_back(temp % 10 + '0');
        carry = temp / 10;
        i--;
        j--;
    }

    std::reverse(result.begin(), result.end());
    return result;
}
