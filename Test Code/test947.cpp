ci::Surface8uRef grayscaleTransform(const ci::Surface8uRef& inputImage) {
    ci::Surface8u outputImage(inputImage->getWidth(), inputImage->getHeight(), false);
    for (int y = 0; y < inputImage->getHeight(); y++) {
        for (int x = 0; x < inputImage->getWidth(); x++) {
            ci::Color8u pixel = inputImage->getPixel(ci::ivec2(x, y));
            uint8_t average = (pixel.r + pixel.g + pixel.b) / 3;
            outputImage.setPixel(ci::ivec2(x, y), ci::Color8u(average, average, average));
        }
    }
    return ci::Surface8uRef(new ci::Surface8u(outputImage));
}
