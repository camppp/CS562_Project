#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> findConsecutiveSubstrings(const string& S) {
    vector<vector<int>> answer;
    int start = -1;
    char last = '\0';

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == last) {
            continue;
        }
        if (i - start >= 3) {
            answer.push_back({start, i - 1});
        }
        start = i;
        last = S[i];
    }
    if (S.size() - start >= 3) {
        answer.push_back({start, S.size() - 1});
    }
    return answer;
}

int main() {
    string S = "aabbbaacc";
    vector<vector<int>> result = findConsecutiveSubstrings(S);
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    return 0;
}
