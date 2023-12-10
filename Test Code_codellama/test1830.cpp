#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct HeaderInfo {
    string license;
    string componentName;
    vector<string> includedHeaders;
};

int main() {
    ifstream headerFile("header.h");
    string line;
    HeaderInfo headerInfo;

    // Read the license identifier
    getline(headerFile, line);
    headerInfo.license = line.substr(line.find("SPDX-License-Identifier: ") + 24);

    // Read the component name
    getline(headerFile, line);
    headerInfo.componentName = line.substr(line.find("#include") + 8);
    headerInfo.componentName = headerInfo.componentName.substr(0, headerInfo.componentName.find(".h"));

    // Read the included header files
    while (getline(headerFile, line)) {
        if (line.find("#include") != string::npos) {
            headerInfo.includedHeaders.push_back(line.substr(line.find("#include") + 8));
        }
    }

    // Output the header information in a structured format
    cout << "License: " << headerInfo.license << endl;
    cout << "Component Name: " << headerInfo.componentName << endl;
    cout << "Included Headers: ";
    for (const string& header : headerInfo.includedHeaders) {
        cout << header << ", ";
    }
    cout << endl;

    return 0;
}
