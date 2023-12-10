#include <memory>

namespace MGL {
    class GraphicsObject {
    public:
        GraphicsObject(std::unique_ptr<Mesh> mesh, ShaderProgram const& shaderProgram)
            : m_mesh(std::move(mesh)), m_shaderProgram(shaderProgram) {}

        void render() {
            if (m_mesh && m_shaderProgram) {
                m_shaderProgram.use();
                m_mesh->draw();
            } else {
                // Handle error: Either mesh or shader program is not valid
                // Example: throw std::runtime_error("Invalid mesh or shader program");
            }
        }

    private:
        std::unique_ptr<Mesh> m_mesh;
        ShaderProgram const& m_shaderProgram;
    };
}
