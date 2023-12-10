#include <iostream>

// Define the file creation flag constants
#define FILE_CREATE 1
#define FILE_SHARE_READ 2

int getFileCreationFlag(bool fCreate) {
    if (fCreate) {
        return FILE_CREATE;
    } else {
        return 0;
    }
}

int main() {
    // Test cases
    std::cout << "getFileCreationFlag(true): " << getFileCreationFlag(true) << std::endl; // Output: FILE_CREATE
    std::cout << "getFileCreationFlag(false): " << getFileCreationFlag(false) << std::endl; // Output: 0
    return 0;
}
