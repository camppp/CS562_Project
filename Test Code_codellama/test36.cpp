#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to search for a file in a given directory
bool searchFile(const string& filePath, const string& directory) {
    // Check if the file path is absolute or relative
    if (filePath.find("/") == 0) {
        // Absolute file path
        if (access(filePath.c_str(), F_OK) == 0) {
            // File found
            return true;
        } else {
            // File not found
            NLOG("File not found: " + filePath);
            return false;
        }
    } else {
        // Relative file path
        string absoluteFilePath = directory + "/" + filePath;
        if (access(absoluteFilePath.c_str(), F_OK) == 0) {
            // File found
            return true;
        } else {
            // File not found
            NLOG("File not found: " + absoluteFilePath);
            return false;
        }
    }
}

// Function to check for the existence of the RCSRESOURCEPATH environment variable
bool checkRCSRESOURCEPATH() {
    char* rcsResourcePath = getenv("RCSRESOURCEPATH");
    if (rcsResourcePath != NULL) {
        // RCSRESOURCEPATH environment variable is set
        return true;
    } else {
        // RCSRESOURCEPATH environment variable is not set
        NLOG("RCSRESOURCEPATH environment variable is not set");
        return false;
    }
}

int main() {
    // Test the file search algorithm
    string filePath = "file.txt";
    string directory = "/home/user/Documents";
    bool found = searchFile(filePath, directory);
    if (found) {
        cout << "File found: " << filePath << endl;
    } else {
        cout << "File not found: " << filePath << endl;
    }

    // Test the RCSRESOURCEPATH environment variable
    bool rcsResourcePathSet = checkRCSRESOURCEPATH();
    if (rcsResourcePathSet) {
        cout << "RCSRESOURCEPATH environment variable is set" << endl;
    } else {
        cout << "RCSRESOURCEPATH environment variable is not set" << endl;
    }

    return 0;
}
