#include <iostream>
#include <fstream>
#include <string>

// Custom exception classes
class FileOpenException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Failed to open the file.";
    }
};

class FileReadException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Failed to read data from the file.";
    }
};

class FileWriteException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Failed to write data to the file.";
    }
};

// Function to read data from a file and perform operations
void processDataFromFile(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        throw FileOpenException();
    }

    // Read data and perform operations
    // ...

    if (/* error while reading data */) {
        throw FileReadException();
    }
}

// Function to write results to another file
void writeDataToFile(const std::string& outputFileName, const std::string& data) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        throw FileOpenException();
    }

    // Write data to the file
    // ...

    if (/* error while writing data */) {
        throw FileWriteException();
    }
}

int main() {
    try {
        processDataFromFile("input.txt");
        writeDataToFile("output.txt", "processed data");
    }
    catch (const FileOpenException& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const FileReadException& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const FileWriteException& ex) {
        std::cerr << ex.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (...) {
        std::cerr << "Caught unknown exception" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
