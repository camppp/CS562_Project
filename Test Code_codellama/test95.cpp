#include <aiko/postprocessing/EdgeFx.h>

namespace aiko {
namespace postprocessing {

EdgeFx::EdgeFx(Shader* shader) : shader_(shader) {
    // Initialize the edge detection shader
    init(shader);
}

void EdgeFx::init(Shader* shader) {
    // Set up the edge detection shader using the provided edge detection kernel
    shader->setUniform("edgeDetectionKernel", edgeDetectionKernel);
    shader->setUniform("edgeDetectionThreshold", edgeDetectionThreshold);
    shader->setUniform("edgeDetectionStrength", edgeDetectionStrength);
}

} // namespace postprocessing
} // namespace aiko
