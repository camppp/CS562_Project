#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> compareQueries(vector<string>& queries, vector<string>& words) {
    vector<int> result;
    for (int i = 0; i < queries.size(); i++) {
        string query = queries[i];
        char smallest_char = query[0];
        int smallest_freq = 0;
        for (char c : query) {
            if (c < smallest_char) {
                smallest_char = c;
                smallest_freq = 1;
            } else if (c == smallest_char) {
                smallest_freq++;
            }
        }

        int num_words = 0;
        for (int j = 0; j < words.size(); j++) {
            string word = words[j];
            char smallest_word_char = word[0];
            int smallest_word_freq = 0;
            for (char c : word) {
                if (c < smallest_word_char) {
                    smallest_word_char = c;
                    smallest_word_freq = 1;
                } else if (c == smallest_word_char) {
                    smallest_word_freq++;
                }
            }
            if (smallest_word_freq < smallest_freq) {
                num_words++;
            }
        }
        result.push_back(num_words);
    }
    return result;
}

int main() {
    vector<string> queries = {"cbd", "bbb", "cc"};
    vector<string> words = {"zaaaz", "b", "cc"};
    vector<int> result = compareQueries(queries, words);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}
