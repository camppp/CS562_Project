#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longest_concatenated_word(vector<string> words) {
    string longest_word;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int j = i + 1; j < words.size(); j++) {
            string other_word = words[j];
            if (word + other_word > longest_word) {
                longest_word = word + other_word;
            }
        }
    }
    return longest_word;
}

int main() {
    vector<string> words = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    string longest_word = longest_concatenated_word(words);
    cout << "Longest word: " << longest_word << endl;
    return 0;
}
