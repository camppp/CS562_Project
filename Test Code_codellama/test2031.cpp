#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Custom exception classes
class FileOpenException : public exception {
public:
    FileOpenException(const string& message) : exception(message) {}
};

class FileReadException : public exception {
public:
    FileReadException(const string& message) : exception(message) {}
};

class FileWriteException : public exception {
public:
    FileWriteException(const string& message) : exception(message) {}
};

// Function to read data from a file and perform some operations on it
void readDataFromFile(const string& inputFile, const string& outputFile) {
    ifstream inputStream(inputFile);
    ofstream outputStream(outputFile);

    if (!inputStream) {
        throw FileOpenException("Failed to open input file");
    }

    // Perform some operations on the data
    // ...

    if (!outputStream) {
        throw FileWriteException("Failed to write to output file");
    }

    // Write the results to the output file
    // ...
}

int main() {
    try {
        readDataFromFile("input.txt", "output.txt");
    } catch (FileOpenException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (FileReadException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (FileWriteException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
