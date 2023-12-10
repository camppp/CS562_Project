#include <string>

using namespace std;

int ctoi(char a) {
    return a - '0';
}

string stringSum(const string& num1, const string& num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    int carry = 0;
    string result = "";

    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? ctoi(num1[i]) : 0;
        int digit2 = (j >= 0) ? ctoi(num2[j]) : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = to_string(sum % 10) + result;
        i--;
        j--;
    }

    return result;
}
