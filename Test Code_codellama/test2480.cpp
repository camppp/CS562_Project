#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> count_keyword_occurrences(const string& file_path, const vector<string>& keywords) {
    ifstream file(file_path);
    map<string, int> keyword_counts;

    string line;
    while (getline(file, line)) {
        for (const string& keyword : keywords) {
            size_t pos = line.find(keyword);
            if (pos != string::npos) {
                keyword_counts[keyword]++;
            }
        }
    }

    return keyword_counts;
}

int main() {
    string file_path = "example.txt";
    vector<string> keywords = {"COPYRIGHT", "LIABILITY", "SOFTWARE"};

    map<string, int> keyword_counts = count_keyword_occurrences(file_path, keywords);

    for (const auto& [keyword, count] : keyword_counts) {
        cout << keyword << ": " << count << endl;
    }

    return 0;
}
