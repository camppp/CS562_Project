#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> count_phrase_occurrences(const string& license_text, const vector<string>& phrases) {
    unordered_map<string, int> counts;
    for (const string& phrase : phrases) {
        int count = 0;
        size_t pos = license_text.find(phrase);
        while (pos != string::npos) {
            count++;
            pos = license_text.find(phrase, pos + phrase.size());
        }
        counts[phrase] = count;
    }
    return counts;
}

int main() {
    string license_text = "Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an \"AS IS\" BASIS,";
    vector<string> phrases = {"distributed", "software", "license"};
    unordered_map<string, int> counts = count_phrase_occurrences(license_text, phrases);
    for (const auto& count : counts) {
        cout << count.first << ": " << count.second << endl;
    }
    return 0;
}
