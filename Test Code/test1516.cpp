#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <header_file>" << endl;
        return 1;
    }

    ifstream header_file(argv[1]);
    if (!header_file) {
        cerr << "Error: unable to open header file" << endl;
        return 1;
    }

    unordered_map<string, int> namespace_counts;

    string line;
    while (getline(header_file, line)) {
        if (line.find("namespace") != string::npos) {
            size_t start = line.find("namespace") + 9;
            size_t end = line.find("{", start);
            string namespace_name = line.substr(start, end - start);
            namespace_counts[namespace_name]++;
        }
    }

    for (const auto& entry : namespace_counts) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
