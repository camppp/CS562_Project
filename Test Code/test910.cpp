#include <iostream>
#include <vector>

// Define the image wrapper data structure
struct ImageWrapper {
    std::vector<unsigned char> imageData;
    int width;
    int height;
    int format;  // e.g., RGB, RGBA
    // Other relevant fields and methods
};

// Function to convert image wrapper to OpenGL texture
GLuint ImageWrapper_to_GLTexture(const ImageWrapper& imageWrapper) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWrapper.width, imageWrapper.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &imageWrapper.imageData[0]);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, 0);  // Unbind the texture
    
    return textureID;
}
