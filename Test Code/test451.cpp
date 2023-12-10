#include <string>
#include <algorithm>
using namespace std;

string sum(string a, string b) {
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0) {
        int digitA = (i >= 0) ? a[i--] - '0' : 0;
        int digitB = (j >= 0) ? b[j--] - '0' : 0;
        int sum = digitA + digitB + carry;
        carry = sum / 10;
        result += to_string(sum % 10);
    }

    reverse(result.begin(), result.end());
    return result;
}
