#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 calculateViewMatrix(glm::vec3 pos, glm::vec3 target, glm::vec3 up) {
    return glm::lookAt(pos, target, up);
}
