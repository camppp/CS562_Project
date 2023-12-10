#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <N>" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    if (!infile) {
        cerr << "Error: unable to open input file " << argv[1] << endl;
        return 1;
    }

    int N = atoi(argv[2]);
    if (N <= 0) {
        cerr << "Error: N must be a positive integer" << endl;
        return 1;
    }

    map<string, int> word_counts;
    string word;
    while (infile >> word) {
        // Ignore common stop words
        if (word == "the" || word == "and" || word == "or" || word == "is") {
            continue;
        }

        // Convert to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Increment word count
        word_counts[word]++;
    }

    // Sort word counts in descending order
    vector<pair<string, int>> sorted_word_counts(word_counts.begin(), word_counts.end());
    sort(sorted_word_counts.begin(), sorted_word_counts.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    // Print top N most frequently occurring words
    for (int i = 0; i < N && i < sorted_word_counts.size(); i++) {
        cout << sorted_word_counts[i].first << ": " << sorted_word_counts[i].second << endl;
    }

    return 0;
}
