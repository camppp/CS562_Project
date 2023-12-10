bool Texture::operator==(const Texture& other) const {
    if (width != other.width || height != other.height) {
        return false; // If dimensions are different, textures are not equal
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (getPixelColor(x, y) != other.getPixelColor(x, y)) {
                return false; // If any pixel color differs, textures are not equal
            }
        }
    }

    return true; // All dimensions and pixel colors are equal, textures are equal
}
