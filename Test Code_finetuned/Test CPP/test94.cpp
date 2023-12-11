#include <array>

namespace aiko {
namespace postprocessing {

class EdgeFx {
public:
    EdgeFx() : shader_(nullptr) {}

    void init(Shader* shader) {
        shader_ = shader;

        // Define the edge detection kernel
        std::array<int, 9> edgeKernel = {
            -1, -1, -1,
            -1,  8, -1,
            -1, -1, -1
        };

        // Set up the shader with the edge detection kernel
        shader_->setUniform("edgeKernel", edgeKernel);

        // Set other necessary configurations for the edge detection effect
        // For example, you might set the edge detection threshold
        shader_->setUniform("edgeThreshold", 0.5f);

        // You might also need to set other uniforms depending on the shader implementation

        // Ensure the shader is properly initialized and ready for use
        shader_->init();
    }

    // Other methods for the EdgeFx class

private:
    Shader* shader_;
};

} // namespace postprocessing
} // namespace aiko