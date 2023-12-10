#include <iostream>
#include <string>
#include <cstring>

// Define the GWBUF structure
struct GWBUF {
    char* data;
    size_t length;
};

// Function to create GWBUF object
GWBUF* create_gwbuf(const std::string& s) {
    // Allocate memory for GWBUF object
    GWBUF* gwbuf = new GWBUF;

    // Initialize length and allocate memory for data
    gwbuf->length = s.length();
    gwbuf->data = new char[gwbuf->length + 1];  // +1 for null terminator

    // Copy input string to GWBUF data
    std::strcpy(gwbuf->data, s.c_str());

    return gwbuf;
}

int main() {
    std::string input = "Hello, GWBUF!";
    GWBUF* gwbuf = create_gwbuf(input);

    // Test the created GWBUF object
    std::cout << "GWBUF data: " << gwbuf->data << std::endl;
    std::cout << "GWBUF length: " << gwbuf->length << std::endl;

    // Clean up memory
    delete[] gwbuf->data;
    delete gwbuf;

    return 0;
}
