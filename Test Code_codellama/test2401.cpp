bool FullscreenQuad::operator<(const FullscreenQuad& other) const {
    // Compare the width of the two quads
    if (width < other.width) {
        return true;
    } else if (width > other.width) {
        return false;
    }

    // Compare the height of the two quads
    if (height < other.height) {
        return true;
    } else if (height > other.height) {
        return false;
    }

    // Compare the color of the two quads
    if (color < other.color) {
        return true;
    } else if (color > other.color) {
        return false;
    }

    // If all other criteria are equal, the two quads are considered equal
    return false;
}
