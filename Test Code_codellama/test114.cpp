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

    string input_file = argv[1];
    int N = atoi(argv[2]);

    ifstream infile(input_file);
    if (!infile) {
        cerr << "Error: unable to open input file " << input_file << endl;
        return 1;
    }

    map<string, int> word_counts;
    string word;
    while (infile >> word) {
        word_counts[word]++;
    }

    vector<pair<string, int>> word_count_pairs;
    for (const auto& entry : word_counts) {
        word_count_pairs.push_back(make_pair(entry.first, entry.second));
    }

    sort(word_count_pairs.begin(), word_count_pairs.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });

    for (int i = 0; i < N && i < word_count_pairs.size(); i++) {
        cout << word_count_pairs[i].first << ": " << word_count_pairs[i].second << endl;
    }

    return 0;
}
