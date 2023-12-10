void TextureManager::loadTexture(const std::string& name, const std::string& filename) {
    // Load the texture from the file
    Texture texture = Texture::loadFromFile(filename);

    // Add the texture to the map
    textures[name] = texture;
}

void TextureManager::unloadTexture(const std::string& name) {
    // Remove the texture from the map
    textures.erase(name);
}
