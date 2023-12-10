#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string makeKey(const string& s) {
    // Generate a key based on the frequency of characters in the string
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    string key;
    for (auto& [c, count] : freq) {
        key += to_string(count) + c;
    }
    return key;
}

unordered_map<string, vector<string>> groupStrings(const vector<string>& strings) {
    unordered_map<string, vector<string>> groups;
    for (const string& s : strings) {
        string key = makeKey(s);
        groups[key].push_back(s);
    }
    return groups;
}

int main() {
    vector<string> strings = {"abc", "bca", "cab", "def", "fed"};
    unordered_map<string, vector<string>> groups = groupStrings(strings);
    for (auto& [key, values] : groups) {
        cout << key << ": ";
        for (const string& s : values) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}
