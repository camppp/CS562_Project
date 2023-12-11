#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>

// Define the image wrapper structure
struct ImageWrapper {
    int width;
    int height;
    int channels;
    unsigned char* data;
};

// Define the OpenGL texture structure
struct GLTexture {
    GLuint texture;
    int width;
    int height;
    int channels;
};

// Function to convert an image wrapper to a OpenGL texture
GLTexture ImageWrapper_to_GLTexture(ImageWrapper image) {
    // Create a new OpenGL texture object
    GLuint texture;
    glGenTextures(1, &texture);

    // Set the texture parameters
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Set the texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);

    // Create a new GLTexture object
    GLTexture glTexture;
    glTexture.texture = texture;
    glTexture.width = image.width;
    glTexture.height = image.height;
    glTexture.channels = image.channels;

    return glTexture;
}

int main() {
    // Create an image wrapper
    ImageWrapper image;
    image.width = 1024;
    image.height = 1024;
    image.channels = 4;
    image.data = new unsigned char[image.width * image.height * image.channels];

    // Fill the image data with some values
    for (int i = 0; i < image.width * image.height * image.channels; i++) {
        image.data[i] = i % 256;
    }

    // Convert the image wrapper to a OpenGL texture
    GLTexture glTexture = ImageWrapper_to_GLTexture(image);

    // Use the OpenGL texture in your OpenGL program
    // ...

    // Clean up the OpenGL texture
    glDeleteTextures(1, &glTexture.texture);

    return 0;
}
