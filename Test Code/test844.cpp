#include <iostream>
#include <string>
#include <set>
using namespace std;

int minUniqueSubstringLength(string S, int len) {
    int N = S.length();
    set<string> X;
    for (int i = 0; i <= N - len; i++) {
        if (X.count(S.substr(i, len)) > 0) {
            return i + len;  // Minimum length of substring found
        }
        X.insert(S.substr(i, len));
    }
    return N;  // If no duplicate substrings found, return the length of the original string
}

int main() {
    string S = "abacabadabacaba";
    int len = 3;
    cout << minUniqueSubstringLength(S, len) << endl;  // Output: 5
    return 0;
}
