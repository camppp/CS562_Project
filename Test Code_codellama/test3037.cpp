#include <GL/glew.h>
#include <GL/gl.h>

class OGLVertexArray {
public:
    OGLVertexArray();
    ~OGLVertexArray();

    Status onInitArray();

private:
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    void initVAO();
    void initVBO();
    void initEBO();
};

OGLVertexArray::OGLVertexArray() {
    vao = 0;
    vbo = 0;
    ebo = 0;
}

OGLVertexArray::~OGLVertexArray() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
}

Status OGLVertexArray::onInitArray() {
    initVAO();
    initVBO();
    initEBO();
    return Status::OK;
}

void OGLVertexArray::initVAO() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
}

void OGLVertexArray::initVBO() {
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void OGLVertexArray::initEBO() {
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
}
