namespace cros_im {
    void loadImage(const std::string& filename) {
        std::cout << "Image loaded from file: " << filename << std::endl;
    }

    void applyFilter(int filterType) {
        std::cout << "Applying filter type: " << filterType << std::endl;
    }

    const int MAX_IMAGE_SIZE = 1000;
}
