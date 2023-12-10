#include <GL/glew.h>
#include <cstdint>

class OpenGLIndexBuffer {
public:
    // Constructor
    OpenGLIndexBuffer(uint32_t* indices, uint32_t count) {
        glGenBuffers(1, &mRendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
        mCount = count;
    }

    // Destructor
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
    uint32_t mRendererID;
    uint32_t mCount;
};
