#include <GL/glew.h>
#include <cstdint>

class OpenGLIndexBuffer {
public:
    // Constructor
    OpenGLIndexBuffer(const uint32_t* indices, uint32_t count);

    // Destructor
    ~OpenGLIndexBuffer();

    // Method to bind the index buffer
    void bind() const;

    // Method to get the count of indices in the buffer
    uint32_t getCount() const;

private:
    // Member variables needed for managing the index buffer
    GLuint mRendererID; // OpenGL ID of the index buffer
    uint32_t mCount;    // Count of indices in the buffer
};

// Constructor implementation
OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* indices, uint32_t count)
    : mCount(count) {
    glGenBuffers(1, &mRendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
}

// Destructor implementation
OpenGLIndexBuffer::~OpenGLIndexBuffer() {
    glDeleteBuffers(1, &mRendererID);
}

// Method to bind the index buffer
void OpenGLIndexBuffer::bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
}

// Method to get the count of indices in the buffer
uint32_t OpenGLIndexBuffer::getCount() const {
    return mCount;
}
