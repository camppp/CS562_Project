#include <stdexcept>
#include <string>
#include <vector>

void DecodeImageFromFile(const std::string& filePath, int width, int height) {
    // Check if the file is a valid image file
    if (!IsValidImageFile(filePath)) {
        throw std::invalid_argument("File is not a valid image file");
    }

    // Decode the image file into the specified dimensions
    std::vector<unsigned char> imageData = DecodeImage(filePath);
    if (imageData.empty()) {
        throw std::runtime_error("Failed to decode image file");
    }

    // Resize the image data to the specified dimensions
    imageData.resize(width * height * 3);

    // Return the decoded image data
    return imageData;
}

bool IsValidImageFile(const std::string& filePath) {
    // Check if the file extension is supported
    std::string extension = GetFileExtension(filePath);
    if (extension != "jpg" && extension != "jpeg" && extension != "png") {
        return false;
    }

    // Check if the file is a valid image file
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        return false;
    }

    // Read the file header
    char header[4];
    file.read(header, 4);

    // Check if the file header is valid
    if (header[0] != 0xFF || header[1] != 0xD8 || header[2] != 0xFF) {
        return false;
    }

    // Check if the file is a JPEG file
    if (extension == "jpg" || extension == "jpeg") {
        // Check if the file is a JPEG file
        if (header[3] != 0xE0) {
            return false;
        }
    }

    // Check if the file is a PNG file
    if (extension == "png") {
        // Check if the file is a PNG file
        if (header[3] != 0x89) {
            return false;
        }
    }

    // Return true if the file is a valid image file
    return true;
}

std::vector<unsigned char> DecodeImage(const std::string& filePath) {
    // Open the file in binary mode
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file");
    }

    // Read the file header
    char header[4];
    file.read(header, 4);

    // Check if the file header is valid
    if (header[0] != 0xFF || header[1] != 0xD8 || header[2] != 0xFF) {
        throw std::runtime_error("Invalid file header");
    }

    // Check if the file is a JPEG file
    if (header[3] == 0xE0) {
        // Decode the JPEG file
        return DecodeJPEG(file);
    }

    // Check if the file is a PNG file
    if (header[3] == 0x89) {
        // Decode the PNG file
        return DecodePNG(file);
    }

    // Return an empty vector if the file is not a valid image file
    return std::vector<unsigned char>();
}

std::vector<unsigned char> DecodeJPEG(std::ifstream& file) {
    // Read the JPEG file header
    char header[4];
    file.read(header, 4);

    // Check if the file header is valid
    if (header[0] != 0xFF || header[1] != 0xD8 || header[2] != 0xFF) {
        throw std::runtime_error("Invalid JPEG file header");
    }

    // Read the JPEG file data
    std::vector<unsigned char> data;
    while (file.good()) {
        // Read the next byte
        unsigned char byte;
        file.read(&byte, 1);

        // Add the byte to the data vector
        data.push_back(byte);
    }

    // Return the decoded JPEG data
    return data;
}

std::vector<unsigned char> DecodePNG(std::ifstream& file) {
    // Read the PNG file header
    char header[4];
    file.read(header, 4);

    // Check if the file header is valid
    if (header[0] != 0x89 || header[1] != 0x50 || header[2] != 0x4E || header[3] != 0x47) {
        throw std::runtime_error("Invalid PNG file header");
    }

    // Read the PNG file data
    std::vector<unsigned char> data;
    while (file.good()) {
        // Read the next byte
        unsigned char byte;
        file.read(&byte, 1);

        // Add the byte to the data vector
        data.push_back(byte);
    }

    // Return the decoded PNG data
    return data;
}
