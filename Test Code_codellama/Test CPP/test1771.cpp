#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

map<string, int> countLicenses(const string& filePath) {
    ifstream file(filePath);
    map<string, int> licenseCounts;

    string line;
    while (getline(file, line)) {
        // Check if the line starts with "//"
        if (line.substr(0, 2) == "//") {
            // Extract the license type from the comment
            string license = line.substr(4);

            // Increment the count for the license type
            licenseCounts[license]++;
        }
    }

    return licenseCounts;
}

int main() {
    string filePath = "path/to/file.txt";
    map<string, int> licenseCounts = countLicenses(filePath);

    for (const auto& licenseCount : licenseCounts) {
        cout << licenseCount.first << ": " << licenseCount.second << endl;
    }

    return 0;
}
