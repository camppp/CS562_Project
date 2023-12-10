#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <source_code_file>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error: unable to open file " << argv[1] << endl;
        return 1;
    }

    unordered_set<string> contributors;

    string line;
    while (getline(file, line)) {
        if (line.find("Copyright (C) ") != string::npos) {
            size_t start = line.find("Copyright (C) ") + 14;
            size_t end = line.find(" by ", start);
            string contributor = line.substr(start, end - start);
            contributors.insert(contributor);
        }
    }

    cout << "Number of unique contributors: " << contributors.size() << endl;

    return 0;
}
