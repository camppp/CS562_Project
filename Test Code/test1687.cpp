#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <source_file>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        cout << "Error: Could not open file " << argv[1] << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("Copyright (C) ") != string::npos) {
            size_t start = line.find("Copyright (C) ") + 14;
            size_t end = line.find(" ", start);
            string year = line.substr(start, end - start);
            cout << "Copyright Year: " << year << endl;

            start = line.find(" ", end + 1);
            end = line.find("All rights reserved.", start);
            string author = line.substr(start, end - start);
            cout << "Author: " << author << endl;
            break;
        }
    }

    file.close();
    return 0;
}
