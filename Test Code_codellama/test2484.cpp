// VertexArray.h
#include <string>

class VertexArray {
public:
    virtual ~VertexArray() = default;

    virtual void bind() = 0;
    virtual void unbind() = 0;
    virtual void setAttribute(const std::string& name, const void* data, size_t size, size_t stride) = 0;
};

// OpenGLVertexArray.h
#include "VertexArray.h"

class OpenGLVertexArray : public VertexArray {
public:
    OpenGLVertexArray(const std::string& name);
    ~OpenGLVertexArray();

    void bind();
    void unbind();
    void setAttribute(const std::string& name, const void* data, size_t size, size_t stride);

private:
    std::string m_name;
    GLuint m_vao;
};

// VertexArrayFactory.h
#include "VertexArray.h"

class VertexArrayFactory {
public:
    static VertexArray* createVertexArray(const std::string& name, Renderer::Implementation implementation);
};

// VertexArrayFactory.cpp
#include "VertexArrayFactory.h"
#include "OpenGLVertexArray.h"

VertexArray* VertexArrayFactory::createVertexArray(const std::string& name, Renderer::Implementation implementation) {
    switch (implementation) {
        case Renderer::Implementation::OpenGL:
            return new OpenGLVertexArray(name);
        default:
            throw std::runtime_error("Unsupported renderer implementation");
    }
}
