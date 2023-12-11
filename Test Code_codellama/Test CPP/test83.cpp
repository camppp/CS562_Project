#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("input.txt");
    string line;
    map<string, int> word_freq;

    // Read the input file and count the frequency of each word
    while (getline(input, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (word_freq.find(word) == word_freq.end()) {
                word_freq[word] = 1;
            } else {
                word_freq[word]++;
            }
        }
    }

    // Sort the words by frequency and print the top N most frequent words
    vector<pair<string, int>> word_freq_vec(word_freq.begin(), word_freq.end());
    sort(word_freq_vec.begin(), word_freq_vec.end(),
         [](const pair<string, int>& a, const pair<string, int>& b) {
             return a.second > b.second;
         });
    for (int i = 0; i < N && i < word_freq_vec.size(); i++) {
        cout << word_freq_vec[i].first << ": " << word_freq_vec[i].second << endl;
    }

    return 0;
}
