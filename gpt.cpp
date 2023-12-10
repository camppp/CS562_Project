#include <iostream>
#include <cstring>

bool copyStringSecurely(const char* source, char* destination, size_t destSize) {
    size_t sourceLength = std::strlen(source);
    if (sourceLength >= destSize) {
        // Truncate source to fit in the destination buffer
        sourceLength = destSize - 1;
    }

    // Copy the string safely
    std::strncpy(destination, source, sourceLength);

    // Ensuring null termination of the string
    destination[sourceLength] = '\0';

    // Return true if no truncation was needed, false otherwise
    return sourceLength < destSize - 1;
}

int main() {
    const int DEST_SIZE = 100;
    char destination[DEST_SIZE];
    const char* source = "This is a sample source string that might be too long for the destination buffer.";

    bool result = copyStringSecurely(source, destination, DEST_SIZE);
    
    std::cout << "Copy Successful: " << std::boolalpha << result << std::endl;
    std::cout << "Destination Buffer: " << destination << std::endl;

    return 0;
}
