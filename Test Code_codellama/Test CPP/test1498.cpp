#include <cstdint>

// Define the OpenGL pixel format constants
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_FLOAT 0x1406

// Define the PixelType class
class PixelType {
public:
    PixelType(int numComponents) : numComponents_(numComponents) {}

    int getNumComponents() const { return numComponents_; }

private:
    int numComponents_;
};

// Define the getPixelFormatSize function
int getPixelFormatSize(int pixelFormat, PixelType pixelType) {
    switch (pixelFormat) {
        case GL_UNSIGNED_INT_24_8:
            return 4; // 4 bytes per component
        case GL_FLOAT:
            return 4; // 4 bytes per component
        default:
            return 0; // Unknown pixel format
    }
}

int main() {
    // Test the function
    int pixelFormat = GL_UNSIGNED_INT_24_8;
    PixelType pixelType(4);
    int size = getPixelFormatSize(pixelFormat, pixelType);
    std::cout << "Size of pixel format " << pixelFormat << " with " << pixelType.getNumComponents() << " components is " << size << " bytes." << std::endl;

    return 0;
}
