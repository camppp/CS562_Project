#include <iostream>
#include <string>
#include <tuple>

using namespace std;

vector<tuple<char, int>> countConsecutiveChars(string s) {
    vector<tuple<char, int>> result;
    char currentChar = s[0];
    int currentCount = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == currentChar) {
            currentCount++;
        } else {
            result.push_back(make_tuple(currentChar, currentCount));
            currentChar = s[i];
            currentCount = 1;
        }
    }

    result.push_back(make_tuple(currentChar, currentCount));

    return result;
}

int main() {
    string s = "aaabbcccc";
    vector<tuple<char, int>> result = countConsecutiveChars(s);

    for (auto& tuple : result) {
        cout << get<0>(tuple) << " " << get<1>(tuple) << endl;
    }

    return 0;
}
