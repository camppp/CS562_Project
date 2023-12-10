#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> countKeywordsInComments(const string& filePath, const vector<string>& keywords) {
    ifstream file(filePath);
    string line;
    map<string, int> keywordCounts;

    while (getline(file, line)) {
        // Check if the line is a comment
        if (line.find("//") != string::npos || line.find("/*") != string::npos) {
            // Extract the comment text
            string comment = line.substr(line.find("//") != string::npos ? line.find("//") : line.find("/*"));

            // Tokenize the comment text
            vector<string> tokens = tokenize(comment);

            // Count the occurrences of each keyword
            for (const string& keyword : keywords) {
                int count = 0;
                for (const string& token : tokens) {
                    if (token == keyword) {
                        count++;
                    }
                }
                keywordCounts[keyword] += count;
            }
        }
    }

    return keywordCounts;
}

int main() {
    string filePath = "example.cpp";
    vector<string> keywords = {"copyright", "redistribution"};
    map<string, int> keywordCounts = countKeywordsInComments(filePath, keywords);

    for (const auto& [keyword, count] : keywordCounts) {
        cout << keyword << ": " << count << endl;
    }

    return 0;
}
