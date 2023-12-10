#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to read the content of a file into a string
string readFile(const string& filename) {
    ifstream file(filename);
    string content;
    file >> content;
    return content;
}

// Function to compare the content of two files and generate an edit script
void compareFiles(const string& file1, const string& file2, const string& outputFile) {
    // Read the content of the two files
    string content1 = readFile(file1);
    string content2 = readFile(file2);

    // Initialize the edit script
    vector<string> editScript;

    // Compare the content of the two files
    for (int i = 0; i < content1.size(); i++) {
        if (content1[i] != content2[i]) {
            // Add an edit operation to the edit script
            editScript.push_back("replace " + to_string(i) + " " + content1[i] + " " + content2[i]);
        }
    }

    // Save the edit script to the output file
    ofstream outFile(outputFile);
    for (int i = 0; i < editScript.size(); i++) {
        outFile << editScript[i] << endl;
    }
}

int main(int argc, char* argv[]) {
    // Check that the command-line arguments are valid
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " file1.txt file2.txt edit_script.txt" << endl;
        return 1;
    }

    // Read the command-line arguments
    string file1 = argv[1];
    string file2 = argv[2];
    string outputFile = argv[3];

    // Compare the content of the two files and generate an edit script
    compareFiles(file1, file2, outputFile);

    return 0;
}
