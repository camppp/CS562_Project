#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countLicenseComments(const string& filePath) {
    ifstream file(filePath);
    string line;
    int count = 0;

    while (getline(file, line)) {
        if (line.find("License") != string::npos || line.find("licence") != string::npos) {
            count++;
        }
    }

    return count;
}

int main() {
    string filePath = "path/to/source/code/file.cpp";
    int count = countLicenseComments(filePath);
    cout << "Number of license-related comments: " << count << endl;
    return 0;
}
