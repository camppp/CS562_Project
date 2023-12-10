#include <fstream>
#include <iostream>
#include <string>

using namespace std;

tuple<string, string> extractCopyrightHolder(const string& filePath) {
    ifstream file(filePath);
    string line;
    string name, email;

    // Skip the first two lines
    getline(file, line);
    getline(file, line);

    // Read the third line
    getline(file, line);
    size_t pos = line.find("Copyright (c)");
    if (pos != string::npos) {
        pos += 13; // Skip "Copyright (c) "
        size_t endPos = line.find('<', pos);
        if (endPos != string::npos) {
            name = line.substr(pos, endPos - pos);
            email = line.substr(endPos + 1, line.length() - endPos - 2);
            return make_tuple(name, email);
        }
    }

    return make_tuple("", "");
}

int main() {
    string filePath = "path/to/license/file.txt";
    tuple<string, string> holder = extractCopyrightHolder(filePath);
    cout << "Name: " << holder.first << endl;
    cout << "Email: " << holder.second << endl;
    return 0;
}
