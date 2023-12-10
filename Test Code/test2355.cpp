#include <iostream>
#include <string>

namespace cros_im {
    void loadImage(const std::string& filename) {
        std::cout << "Image loaded from file: " << filename << std::endl;
    }

    void applyFilter(int filterType) {
        std::cout << "Applying filter type: " << filterType << std::endl;
    }

    const int MAX_IMAGE_SIZE = 1920; // Example maximum image size

    // Other image processing functions and constants can be added here
}

int main() {
    cros_im::loadImage("example_image.jpg");
    cros_im::applyFilter(2);
    std::cout << "Maximum image size: " << cros_im::MAX_IMAGE_SIZE << std::endl;
    return 0;
}
