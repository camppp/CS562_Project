#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("license.txt");
    string line;
    map<string, int> word_counts;

    // Read the file line by line
    while (getline(file, line)) {
        // Tokenize the line into words
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // Ignore case sensitivity and common stop words
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if (word != "the" && word != "and" && word != "or" && word != "is") {
                words.push_back(word);
            }
        }

        // Increment the count for each word
        for (string word : words) {
            word_counts[word]++;
        }
    }

    // Output the top 5 most frequently occurring words
    vector<pair<string, int>> top_words;
    for (auto it = word_counts.begin(); it != word_counts.end(); it++) {
        top_words.push_back(make_pair(it->first, it->second));
    }
    sort(top_words.begin(), top_words.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < 5 && i < top_words.size(); i++) {
        cout << top_words[i].first << ": " << top_words[i].second << endl;
    }

    return 0;
}
