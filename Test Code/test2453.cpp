void Texture::LoadTexture(const std::string& file)
{
    // Generate a texture ID
    GLCall(glGenTextures(1, &m_RendererID));

    // Bind the texture for configuration
    Bind();

    // Load the texture from file using appropriate library (not shown here)

    // Set texture parameters
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
}
