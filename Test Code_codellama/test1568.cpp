#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> countDistinctCharacters(const string& str) {
    unordered_map<char, int> counts;
    for (char c : str) {
        counts[c]++;
    }
    return counts;
}

int main() {
    string str = "abracadabra";
    unordered_map<char, int> counts = countDistinctCharacters(str);
    for (auto& count : counts) {
        cout << count.first << " " << count.second << endl;
    }
    return 0;
}
