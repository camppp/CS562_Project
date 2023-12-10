#include <cstdint>
#include <glad/glad.h>

class OpenGLIndexBuffer {
public:
    // Constructor and Destructor
    OpenGLIndexBuffer(const uint32_t* data, uint32_t count);
    ~OpenGLIndexBuffer();

    // Method to bind the index buffer
    void bind() const;

    // Method to get the count of indices in the buffer
    uint32_t getCount() const;

private:
    // Member variables needed for managing the index buffer
    uint32_t mRendererID;
    uint32_t mCount;

    // Method to create the index buffer
    void createBuffer();

    // Method to delete the index buffer
    void deleteBuffer();
};

// Constructor and Destructor
OpenGLIndexBuffer::OpenGLIndexBuffer(const uint32_t* data, uint32_t count)
    : mRendererID(0), mCount(count)
{
    createBuffer();
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
    deleteBuffer();
}

// Method to bind the index buffer
void OpenGLIndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
}

// Method to get the count of indices in the buffer
uint32_t OpenGLIndexBuffer::getCount() const
{
    return mCount;
}

// Method to create the index buffer
void OpenGLIndexBuffer::createBuffer()
{
    glGenBuffers(1, &mRendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mCount * sizeof(uint32_t), data, GL_STATIC_DRAW);
}

// Method to delete the index buffer
void OpenGLIndexBuffer::deleteBuffer()
{
    glDeleteBuffers(1, &mRendererID);
}
