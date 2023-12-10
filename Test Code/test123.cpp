#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> wordFrequency(const string& text, const vector<string>& stopWords) {
    unordered_map<string, int> frequency;
    istringstream iss(text);
    string word;
    while (iss >> word) {
        // Ignore punctuation and convert to lowercase
        word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        // Check if the word is a stop word
        if (find(stopWords.begin(), stopWords.end(), word) == stopWords.end()) {
            // Increment the frequency of the word
            frequency[word]++;
        }
    }
    return frequency;
}

int main() {
    string text = "Unless required by applicable law or agreed to in writing, software";
    vector<string> stopWords = {"the", "and", "of", "in", "to", "by", "or"};
    unordered_map<string, int> frequency = wordFrequency(text, stopWords);
    for (const auto& word : frequency) {
        cout << word.first << ": " << word.second << endl;
    }
    return 0;
}
