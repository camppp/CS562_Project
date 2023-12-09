#include <cstdint>
#include <GL/glew.h>

class OpenGLIndexBuffer {
public:
    // Constructor and Destructor
    OpenGLIndexBuffer(uint32_t count, const void* data, GLenum usage) {
        glGenBuffers(1, &mRendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, usage);
    }

    ~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &mRendererID);
    }

    // Method to bind the index buffer
    void bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    }

    // Method to get the count of indices in the buffer
    uint32_t getCount() const {
        return mCount;
    }

private:
    // Member variables needed for managing the index buffer
    uint32_t mRendererID;
    uint32_t mCount;
};