#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <file_path>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file) {
        cerr << "Error: unable to open file " << argv[1] << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("License") != string::npos || line.find("licence") != string::npos) {
            cout << line << endl;
        }
    }

    return 0;
}
