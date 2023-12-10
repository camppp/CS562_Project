#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <sstream>

struct ImageRGBA {
    int width;
    int height;
    std::vector<unsigned char> data;
};

std::string GetFileExtension(const std::string& file) {
    size_t dotPos = file.find_last_of(".");
    if (dotPos != std::string::npos) {
        return file.substr(dotPos + 1);
    }
    return "";
}

void ReadImageFromFile(const std::string& file, ImageRGBA& image) {
    std::string ext = GetFileExtension(file);
    if (ext != "png" && ext != "tga" && ext != "bmp" && ext != "psd"
            && ext != "gif" && ext != "jpg") {
        throw std::runtime_error("Could not read file " + file);
    }

    // Assuming image reading and processing code here
    // For the purpose of this example, let's assume the image data is read from the file and stored in a vector
    std::ifstream fileStream(file, std::ios::binary);
    if (fileStream) {
        // Read image data and set width, height, and data in the ImageRGBA object
        // Example: Read image dimensions and data into image.width, image.height, and image.data
    } else {
        throw std::runtime_error("Failed to open file " + file);
    }
}

int main() {
    ImageRGBA image;
    try {
        ReadImageFromFile("example.png", image);
        // Process the image data
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
