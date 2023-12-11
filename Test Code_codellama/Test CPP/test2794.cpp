#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int validateFastaFile(const string& filePath, int expectedNumSequences) {
    ifstream file(filePath);
    if (!file) {
        cerr << "Error: unable to open file " << filePath << endl;
        return -1;
    }

    int numSequences = 0;
    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] != '>') {
            continue;
        }
        numSequences++;
    }

    if (numSequences != expectedNumSequences) {
        cerr << "Error: expected " << expectedNumSequences << " sequences, but found " << numSequences << endl;
        return -1;
    }

    return 0;
}
