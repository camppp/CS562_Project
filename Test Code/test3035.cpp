#include <iostream>
#include <fstream>
#include <string>

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

    string line;
    int disclaimers = 0;

    while (getline(file, line)) {
        if (line.find("/*") != string::npos && line.find("*/") != string::npos) {
            string disclaimer = line.substr(line.find("/*") + 2, line.find("*/") - line.find("/*") - 2);
            if (disclaimer.find("DISCLAIMER") != string::npos) {
                disclaimers++;
            }
        }
    }

    cout << "Total number of legal disclaimers: " << disclaimers << endl;

    return 0;
}
