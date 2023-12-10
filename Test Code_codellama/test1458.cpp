#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <license_file>" << endl;
        return 1;
    }

    string license_file = argv[1];
    ifstream infile(license_file);
    if (!infile) {
        cerr << "Error: unable to open license file " << license_file << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        if (line.find("Copyright (c) ") != string::npos) {
            string copyright_line = line.substr(line.find("Copyright (c) ") + 13);
            string copyright_holder = copyright_line.substr(0, copyright_line.find(" "));
            string year_of_copyright = copyright_line.substr(copyright_line.find(" ") + 1);
            cout << "Copyright Holder: " << copyright_holder << endl;
            cout << "Year of Copyright: " << year_of_copyright << endl;
            break;
        }
    }

    return 0;
}
