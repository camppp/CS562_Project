#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> findSubstrings(string s) {
    vector<pair<int, int>> result;
    for (int i = 0; i < s.length() - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) {
            result.push_back(make_pair(i, i + 2));
        }
    }
    return result;
}

int main() {
    string s = "aabbbaacc";
    vector<pair<int, int>> substrings = findSubstrings(s);
    for (auto pair : substrings) {
        cout << "[" << pair.first << ", " << pair.second << "]" << endl;
    }
    return 0;
}
