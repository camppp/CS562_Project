class Mesh {
private:
    unsigned int vao;
    unsigned int vbo;
    unsigned int ebo;

public:
    // Constructor
    Mesh(unsigned int vao, unsigned int vbo, unsigned int ebo) : vao(vao), vbo(vbo), ebo(ebo) {}

    // Swap function to exchange the contents of two Mesh objects
    static void swap(Mesh& a, Mesh& b) {
        std::swap(a.vao, b.vao);
        std::swap(a.vbo, b.vbo);
        std::swap(a.ebo, b.ebo);
    }

    // Getters for the private fields
    unsigned int getVAO() { return vao; }
    unsigned int getVBO() { return vbo; }
    unsigned int getEBO() { return ebo; }

    // Destructor to release any allocated resources
    ~Mesh() {
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glDeleteVertexArrays(1, &vao);
    }
};
