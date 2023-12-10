#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countUniqueHeaderFiles(const string& sourceCode) {
    vector<string> headerFiles;
    string includeDirective = "#include";
    string headerFile;

    // Iterate through the lines of the source code
    for (string line : sourceCode) {
        // Check if the line contains an include directive
        if (line.find(includeDirective) != string::npos) {
            // Extract the header file name from the include directive
            headerFile = line.substr(includeDirective.length());
            // Remove any whitespace characters from the header file name
            headerFile = headerFile.trim();
            // Add the header file to the list of header files if it is not already present
            if (find(headerFiles.begin(), headerFiles.end(), headerFile) == headerFiles.end()) {
                headerFiles.push_back(headerFile);
            }
        }
    }

    // Return the number of unique header files
    return headerFiles.size();
}
