#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<pair<string, int>> topNWords(const string& filename, int N) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: unable to open file " << filename << endl;
        return {};
    }

    // Create a map to store the word frequencies
    map<string, int> freqs;

    // Read the file and update the frequency map
    string word;
    while (infile >> word) {
        // Ignore common stop words
        if (word == "the" || word == "and" || word == "is") {
            continue;
        }

        // Update the frequency count for the word
        freqs[word]++;
    }

    // Create a vector to store the top N words
    vector<pair<string, int>> top_words;

    // Iterate over the frequency map and add the top N words to the vector
    for (const auto& entry : freqs) {
        top_words.push_back(entry);
        if (top_words.size() == N) {
            break;
        }
    }

    // Sort the vector by frequency count (descending)
    sort(top_words.begin(), top_words.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Return the top N words
    return top_words;
}

int main() {
    vector<pair<string, int>> top_words = topNWords("sample.txt", 3);
    for (const auto& entry : top_words) {
        cout << entry.first << ": " << entry.second << endl;
    }
    return 0;
}
