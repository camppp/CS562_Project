#include <vector>
#include <cassert>

struct Vertex {
  float x, y, z;
  // Other vertex attributes can be added here
};

enum class RenderMode { TriangleStrip, TriangleList, Points };

class Renderer {
public:
  void renderImmediate(RenderMode mode, const Vertex* vertices, size_t size) {
    // Implementation of rendering the mesh
  }
};

class MeshBuilder {
public:
  MeshBuilder(RenderMode renderMode) : m_renderMode{renderMode} {}

  void addVertex(const Vertex& vertex) {
    m_vertices.push_back(vertex);
  }

  void clear() {
    m_vertices.clear();
  }

  void submit(Renderer& renderer) {
    assert(!m_vertices.empty());  // Submitting empty mesh.

    renderer.renderImmediate(m_renderMode, m_vertices.data(), m_vertices.size());
  }

private:
  RenderMode m_renderMode;
  std::vector<Vertex> m_vertices;
};
