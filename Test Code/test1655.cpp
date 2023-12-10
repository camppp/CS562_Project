#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    // Open the header file
    ifstream headerFile("example.hpp");

    // Check if the file is open
    if (!headerFile.is_open()) {
        cout << "Error: Could not open header file" << endl;
        return 1;
    }

    // Read the header file line by line
    string line;
    while (getline(headerFile, line)) {
        // Check if the line contains a constant definition
        if (line.find("static const") != string::npos) {
            // Extract the constant name and value
            string constantName = line.substr(line.find("static const") + 13);
            constantName = constantName.substr(0, constantName.find(" "));
            string constantValue = line.substr(line.find("=") + 2);
            constantValue = constantValue.substr(0, constantValue.find(";"));

            // Print the constant name and value
            cout << constantName << " = " << constantValue << endl;
        }
    }

    // Close the header file
    headerFile.close();

    return 0;
}
