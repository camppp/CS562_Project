#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> extractRestrictions(const string& filePath) {
    vector<vector<string>> restrictions;

    ifstream file(filePath);
    if (!file) {
        cerr << "Error: unable to open file " << filePath << endl;
        return restrictions;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        vector<string> restriction;
        restriction.push_back(line);

        while (getline(file, line) && !line.empty()) {
            restriction.push_back(line);
        }

        restrictions.push_back(restriction);
    }

    return restrictions;
}
