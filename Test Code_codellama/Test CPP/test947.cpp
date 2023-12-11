ci::Surface8uRef grayscaleTransform(const ci::Surface8uRef& inputImage) {
    // Create a new image with the same dimensions as the input image
    ci::Surface8uRef outputImage = ci::Surface8u::create(inputImage->getWidth(), inputImage->getHeight());

    // Loop through each pixel in the input image and convert it to grayscale
    for (int y = 0; y < inputImage->getHeight(); y++) {
        for (int x = 0; x < inputImage->getWidth(); x++) {
            // Get the RGB values of the current pixel
            ci::ColorA8u color = inputImage->getPixel(x, y);

            // Calculate the grayscale value by averaging the RGB values
            uint8_t grayscaleValue = (color.r + color.g + color.b) / 3;

            // Set the grayscale value for the current pixel in the output image
            outputImage->setPixel(x, y, ci::ColorA8u(grayscaleValue, grayscaleValue, grayscaleValue, 255));
        }
    }

    return outputImage;
}
