void processImage(std::uint8_t* buffer, int width, int height) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = 4 * (y * width + x);
            buffer[index] = 255 - buffer[index];         // Invert red channel
            buffer[index + 1] = 255 - buffer[index + 1]; // Invert green channel
            buffer[index + 2] = 255 - buffer[index + 2]; // Invert blue channel
            // Alpha channel remains unchanged
        }
    }
}
