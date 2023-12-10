#include <iostream>
#include <string>

// Define the structure representing the color of a pixel
struct PixelColor {
    unsigned char r;  // Red component
    unsigned char g;  // Green component
    unsigned char b;  // Blue component
    unsigned char a;  // Alpha component
};

// Define the Image class with the getPixel method
class Image {
public:
    PixelColor getPixel(int x, int y) const {
        // Implementation of getPixel method
        // Assume the method returns the PixelColor structure for the given coordinates
    }
};

// Function to get the color information of a pixel
std::string getPixelColor(const Image& image, int x, int y) {
    PixelColor pixel = image.getPixel(x, y);
    return "Pixel (" + std::to_string(x) + ", " + std::to_string(y) + ") has color (" +
           std::to_string(static_cast<int>(pixel.r)) + ", " +
           std::to_string(static_cast<int>(pixel.g)) + ", " +
           std::to_string(static_cast<int>(pixel.b)) + ", " +
           std::to_string(static_cast<int>(pixel.a)) + ")";
}

// Example usage
int main() {
    Image m_Image;  // Assume m_Image is initialized with the image data
    int x = 3, y = 4;
    std::cout << getPixelColor(m_Image, x, y) << std::endl;
    return 0;
}
