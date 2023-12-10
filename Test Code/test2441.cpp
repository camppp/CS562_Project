#include <string>
#include "Texture.h" // Assuming Texture class is available

enum class TextureFormat {
    RGBA,
    RGB,
    // Add more formats as needed
};

enum class TextureFilter {
    GL_NEAREST,
    GL_LINEAR,
    // Add more filters as needed
};

void loadAndSetTexture(const std::string& filePath, TextureFormat format, TextureFilter minFilter, TextureFilter magFilter) {
    Texture texture;
    texture.loadFromFile(filePath, format == TextureFormat::RGBA ? TEXTURE_PIXEL_FORMAT_RGBA : TEXTURE_PIXEL_FORMAT_RGB);
    texture.setMinFilter(static_cast<GLenum>(minFilter));
    texture.setMagFilter(static_cast<GLenum>(magFilter));
}
