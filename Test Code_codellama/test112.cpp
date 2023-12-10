#include <iostream>
#include <fstream>
#include <string>
#include <hs_common.h>

void processRecords(const char* filename) {
    // Open the binary file
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: failed to open file " << filename << std::endl;
        return;
    }

    // Read the records one by one
    while (file.good()) {
        // Read the header
        RecordHeader header;
        file.read((char*)&header, sizeof(header));

        // Check if the header is valid
        if (header.length == 0 || header.type == 0) {
            std::cerr << "Error: invalid header" << std::endl;
            break;
        }

        // Read the payload
        std::string payload(header.length, ' ');
        file.read((char*)payload.data(), header.length);

        // Process the payload based on its type
        switch (header.type) {
            case 1:
                // Process a string payload
                std::cout << "String payload: " << payload << std::endl;
                break;
            case 2:
                // Process an integer payload
                std::cout << "Integer payload: " << std::stoi(payload) << std::endl;
                break;
            default:
                std::cerr << "Error: unknown payload type" << std::endl;
                break;
        }
    }

    // Close the file
    file.close();
}
