std::string getPixelColor(const Image& image, int x, int y) {
    // Get the pixel at the specified coordinates
    auto pixel = image.getPixel(x, y);

    // Format the color information as a string
    std::stringstream ss;
    ss << "Pixel (" << x << ", " << y << ") has color (" << pixel.r << ", " << pixel.g << ", " << pixel.b << ", " << pixel.a << ")";

    // Return the formatted string
    return ss.str();
}
