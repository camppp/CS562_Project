#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>

class Transform {
public:
    glm::vec3 scale;
    glm::quat rotation;
    glm::vec3 position;

    Transform(glm::mat4 matrix) {
        glm::vec3 skew;
        glm::vec4 perspective;
        glm::decompose(matrix, scale, rotation, position, skew, perspective);
    }
};

// Example usage
int main() {
    glm::mat4 transformationMatrix = glm::mat4(1.0f);  // Replace with actual transformation matrix
    Transform transformObj(transformationMatrix);

    // Access the extracted components
    glm::vec3 extractedScale = transformObj.scale;
    glm::quat extractedRotation = transformObj.rotation;
    glm::vec3 extractedPosition = transformObj.position;

    // Use the extracted components as needed
    // ...
    return 0;
}
