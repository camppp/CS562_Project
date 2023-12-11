#include <fstream>
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, int> find_license_agreement(const string& file_path) {
    ifstream file(file_path);
    if (!file) {
        cerr << "Error: unable to open file " << file_path << endl;
        return make_tuple(-1, -1);
    }

    int start_line = -1;
    int end_line = -1;

    string line;
    while (getline(file, line)) {
        if (line.find(" ** ") != string::npos) {
            if (start_line == -1) {
                start_line = file.tellg();
            }
            end_line = file.tellg();
        }
    }

    if (start_line != -1 && end_line != -1) {
        return make_tuple(start_line, end_line);
    } else {
        return make_tuple(-1, -1);
    }
}

int main() {
    string file_path = "license.txt";
    tuple<int, int> result = find_license_agreement(file_path);
    if (result.first == -1 && result.second == -1) {
        cout << "License agreement not found" << endl;
    } else {
        cout << "License agreement found starting at line " << result.first << " and ending at line " << result.second << endl;
    }
    return 0;
}
