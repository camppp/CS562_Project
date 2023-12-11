void loadAndSetTexture(const std::string& filePath, TextureFormat format, TextureFilter minFilter, TextureFilter magFilter) {
    // Load the texture from the given file path
    GLuint textureID = loadTexture(filePath, format);

    // Set the minification and magnification filtering options for the loaded texture
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}
