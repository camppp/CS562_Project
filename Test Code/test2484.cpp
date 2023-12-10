// VertexArray.hpp
#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP

#include <iostream>
#include <stdexcept>

// Abstract base class for vertex arrays
class VertexArray {
public:
    virtual ~VertexArray() = default;
    virtual void bind() const = 0;
    virtual void unbind() const = 0;
};

// Concrete class for handling vertex arrays in an OpenGL rendering context
class OpenGLVertexArray : public VertexArray {
public:
    void bind() const override {
        std::cout << "Binding OpenGL vertex array" << std::endl;
        // Implement OpenGL-specific binding logic
    }

    void unbind() const override {
        std::cout << "Unbinding OpenGL vertex array" << std::endl;
        // Implement OpenGL-specific unbinding logic
    }
};

// Factory method for creating vertex arrays based on the renderer implementation
class VertexArrayFactory {
public:
    enum class Renderer::Implementation {
        opengl,
        // Add other supported renderer implementations here
    };

    static VertexArray* createVertexArray(Renderer::Implementation implementation) {
        switch (implementation) {
            case Renderer::Implementation::opengl:
                return new OpenGLVertexArray();
            default:
                throw std::runtime_error("The requested renderer implementation is not supported.");
                return nullptr;
        }
    }
};

#endif // VERTEXARRAY_HPP
