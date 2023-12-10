c++
#include <iostream>
#include <vector>
#include <string>
#include <QBetaKarttakuva>

void processAndSaveImages(const std::vector<std::string>& imagePaths, const std::string& outputDirectory) {
    for (const auto& imagePath : imagePaths) {
        // Load the image
        QBetaKarttakuva::Image image;
        if (!QBetaKarttakuva::loadImage(imagePath, image)) {
            std::cerr << "Error loading image: " << imagePath << std::endl;
            continue;
        }

        // Apply the processing algorithm
        QBetaKarttakuva::applyProcessingAlgorithm(image);

        // Save the processed image
        std::string outputPath = outputDirectory + "/" + imagePath.substr(imagePath.find_last_of('/') + 1);
        if (!QBetaKarttakuva::saveImage(image, outputPath)) {
            std::cerr << "Error saving image: " << outputPath << std::endl;
            continue;
        }
    }
}
