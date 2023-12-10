#include <iostream>
#include <unordered_map>

class PixelType {
public:
    int components;

    PixelType(int components) : components(components) {}
};

int getPixelFormatSize(int pixelFormat, PixelType pixelType) {
    std::unordered_map<int, int> formatSizeMap = {
        { GL_UNSIGNED_INT_24_8, pixelType.components * 4 },
        { GL_FLOAT, pixelType.components * 4 }
    };

    if (formatSizeMap.find(pixelFormat) != formatSizeMap.end()) {
        return formatSizeMap[pixelFormat];
    } else {
        // Handle unknown pixel format
        return -1;
    }
}

int main() {
    // Example usage
    PixelType pixelType1(4);
    std::cout << getPixelFormatSize(GL_UNSIGNED_INT_24_8, pixelType1) << std::endl;  // Output: 8

    PixelType pixelType2(3);
    std::cout << getPixelFormatSize(GL_FLOAT, pixelType2) << std::endl;  // Output: 12
    return 0;
}
