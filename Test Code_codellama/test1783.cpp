class MeshBuilder {
private:
    std::vector<Vertex> m_vertices;
    RenderMode m_renderMode;

public:
    MeshBuilder(RenderMode renderMode) : m_renderMode(renderMode) {}

    void addVertex(const Vertex& vertex) {
        m_vertices.push_back(vertex);
    }

    void clear() {
        m_vertices.clear();
    }

    void submit(Renderer& renderer) {
        assert(!m_vertices.empty());
        renderer.renderImmediate(m_renderMode, m_vertices.data(), m_vertices.size());
    }
};
