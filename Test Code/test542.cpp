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

    // Read the license agreement from the file
    while (getline(file, line)) {
        // Split the line into individual words
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // Increment the count for each word
        for (string word : words) {
            if (word_counts.find(word) != word_counts.end()) {
                word_counts[word]++;
            } else {
                word_counts[word] = 1;
            }
        }
    }

    // Sort the word counts in descending order
    vector<pair<string, int>> sorted_word_counts(word_counts.begin(), word_counts.end());
    sort(sorted_word_counts.begin(), sorted_word_counts.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Print the top N most frequently occurring words
    int n = 2;
    for (int i = 0; i < n && i < sorted_word_counts.size(); i++) {
        cout << sorted_word_counts[i].first << ": " << sorted_word_counts[i].second << endl;
    }

    return 0;
}
