#include <iostream>
#include <cmath>

class SharpenFilter {
public:
    SharpenFilter() {
        initSprite(nullptr);
    }

    void setAttributes(GLProgram* cgp) {
        // Set the attributes for the filter's GLProgram
    }

    void applyFilter(Image* inputImage, Image* outputImage) {
        // Apply the sharpening filter to the input image and store the result in the output image
        for (int i = 0; i < inputImage->getHeight(); i++) {
            for (int j = 0; j < inputImage->getWidth(); j++) {
                // Calculate the sharpening effect for the current pixel
                float sharpeningEffect = 0.0f;
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        // Calculate the gradient magnitude for the current pixel
                        float gradientMagnitude = sqrt(pow(inputImage->getPixel(i + k, j + l).r - inputImage->getPixel(i, j).r, 2) +
                                                       pow(inputImage->getPixel(i + k, j + l).g - inputImage->getPixel(i, j).g, 2) +
                                                       pow(inputImage->getPixel(i + k, j + l).b - inputImage->getPixel(i, j).b, 2));
                        // Calculate the sharpening effect for the current pixel
                        sharpeningEffect += gradientMagnitude * (inputImage->getPixel(i + k, j + l).r - inputImage->getPixel(i, j).r);
                    }
                }
                // Apply the sharpening effect to the current pixel
                outputImage->setPixel(i, j, inputImage->getPixel(i, j) + sharpeningEffect);
            }
        }
    }
};
