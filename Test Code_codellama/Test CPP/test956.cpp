void processImage(std::uint8_t* buffer, int width, int height) {
    for (int i = 0; i < width * height; i += 4) {
        buffer[i] = 255 - buffer[i];
        buffer[i + 1] = 255 - buffer[i + 1];
        buffer[i + 2] = 255 - buffer[i + 2];
    }
}
