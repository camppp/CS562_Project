++
#include "qbetakarttakuva.h"

void processAndSaveImages(const std::vector<std::string>& imagePaths, const std::string& outputDirectory) {
    for (const auto& imagePath : imagePaths) {
        Image image;
        if (loadImage(imagePath, image)) {
            applyProcessingAlgorithm(image);
            std::string outputFilePath = outputDirectory + "/" + getImageFileName(imagePath);
            if (!saveImage(image, outputFilePath)) {
                std::cerr << "Error: Failed to save processed image to " << outputFilePath << std::endl;
            }
        } else {
            std::cerr << "Error: Failed to load image from " << imagePath << std::endl;
        }
    }
}

std::string getImageFileName(const std::string& imagePath) {
    size_t found = imagePath.find_last_of("/\\");
    if (found != std::string::npos) {
        return imagePath.substr(found + 1);
    }
    return imagePath;
}
