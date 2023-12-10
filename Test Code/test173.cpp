int ShadowedBorderTextureMaterial::compare(const QSGMaterial *other) const {
    auto material = static_cast<const ShadowedBorderTextureMaterial *>(other);

    auto result = ShadowedBorderRectangleMaterial::compare(other);
    if (result != 0) {
        return result;
    }

    // Compare additional properties of ShadowedBorderTextureMaterial
    // Example: Compare additional properties such as texture, shadow, etc.
    // Replace the following placeholder with the actual comparison logic
    if (this->texture != material->texture) {
        return (this->texture < material->texture) ? -1 : 1;
    }

    if (this->shadow != material->shadow) {
        return (this->shadow < material->shadow) ? -1 : 1;
    }

    // If all properties are equal, return 0
    return 0;
}
