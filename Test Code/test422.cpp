#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>

struct ImageRGBA {
    int width;
    int height;
    std::vector<unsigned char> data;
};

void ReadImageFromFile(const std::string& file, ImageRGBA& image) {
    // Validate the file extension
    std::string extension = file.substr(file.find_last_of('.') + 1);
    if (extension != "png" && extension != "tga" && extension != "bmp" && extension != "psd" && extension != "gif" && extension != "jpg") {
        throw std::runtime_error("Invalid file extension: " + extension);
    }

    // Open the file
    std::ifstream fileStream(file, std::ios::binary);
    if (!fileStream.is_open()) {
        throw std::runtime_error("Failed to open file: " + file);
    }

    // Read the image data
    image.width = 0;
    image.height = 0;
    image.data.clear();
    fileStream.read((char*)&image.width, sizeof(int));
    fileStream.read((char*)&image.height, sizeof(int));
    image.data.resize(image.width * image.height * 4);
    fileStream.read((char*)image.data.data(), image.data.size());

    // Close the file
    fileStream.close();
}
