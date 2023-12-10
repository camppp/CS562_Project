// Implement the swap function to exchange the contents of two Mesh objects
void Mesh::swap(Mesh& a, Mesh& b) {
    using std::swap;
    swap(a.vao, b.vao);
    swap(a.vbo, b.vbo);
    swap(a.ebo, b.ebo);
}

// Implement getters for the private fields
unsigned int Mesh::getVAO() {
    return vao;
}

unsigned int Mesh::getVBO() {
    return vbo;
}

unsigned int Mesh::getEBO() {
    return ebo;
}

// Implement the destructor to release any allocated resources
Mesh::~Mesh() {
    // Release VAO, VBO, EBO resources here (e.g., using OpenGL functions)
    // Example:
    // glDeleteVertexArrays(1, &vao);
    // glDeleteBuffers(1, &vbo);
    // glDeleteBuffers(1, &ebo);
}
