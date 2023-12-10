#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::vec3 applyRotations(const glm::vec3& initialPosition, float ry, float rz) {
    glm::mat4 roty = glm::rotate(glm::mat4(1.0f), glm::radians(ry), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 rotz = glm::rotate(glm::mat4(1.0f), glm::radians(rz), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::vec4 position4(initialPosition, 1.0f);  // Convert initial position to homogeneous coordinates

    // Apply rotations to the position
    position4 = rotz * roty * position4;

    // Convert the resulting position back to 3D vector
    return glm::vec3(position4);
}
