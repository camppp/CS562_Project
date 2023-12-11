bool Texture::operator==(const Texture& other) const {
    // Check if the dimensions of the two textures are equal
    if (width != other.width || height != other.height) {
        return false;
    }

    // Check if the pixels of the two textures are equal
    for (int i = 0; i < width * height; i++) {
        if (pixels[i] != other.pixels[i]) {
            return false;
        }
    }

    // If the dimensions and pixels are equal, the textures are considered equal
    return true;
}
