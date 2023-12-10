#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile("sample.txt");
    string line;
    map<string, int> word_counts;

    while (getline(infile, line)) {
        // Tokenize the line into individual words
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // Ignore common stop words and convert to lowercase
            if (word != "the" && word != "and" && word != "is") {
                word = to_lower(word);
                // Increment the count for the current word
                word_counts[word]++;
            }
        }
    }

    // Output the top N most frequent words and their counts
    vector<pair<string, int>> top_words;
    for (const auto& word_count : word_counts) {
        top_words.push_back(word_count);
    }
    sort(top_words.begin(), top_words.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });
    for (int i = 0; i < 3; i++) {
        cout << top_words[i].first << ": " << top_words[i].second << endl;
    }

    return 0;
}
