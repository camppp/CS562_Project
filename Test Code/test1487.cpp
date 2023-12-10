#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int countNonEmptyLines(const string& labelsFilePath, const string& trainFilePath) {
    ifstream labelsFile(labelsFilePath);
    ifstream trainFile(trainFilePath);

    int labelsCount = 0;
    int trainCount = 0;

    string line;
    while (getline(labelsFile, line)) {
        if (!line.empty()) {
            labelsCount++;
        }
    }

    while (getline(trainFile, line)) {
        if (!line.empty()) {
            trainCount++;
        }
    }

    return labelsCount + trainCount;
}

int main() {
    string labelsFilePath = "config/labels.txt";
    string trainFilePath = "config/train.txt";

    int totalCount = countNonEmptyLines(labelsFilePath, trainFilePath);

    cout << "Total count of non-empty lines in both files: " << totalCount << endl;

    return 0;
}
