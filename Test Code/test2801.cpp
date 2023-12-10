#include <glm/glm.hpp>

glm::mat4 calculateViewMatrix(glm::vec3 pos, glm::vec3 target, glm::vec3 up)
{
    // Calculate the direction vector from the camera position to the target
    glm::vec3 dir = glm::normalize(target - pos);

    // Calculate the right vector by cross-producting the up vector with the direction vector
    glm::vec3 right = glm::normalize(glm::cross(up, dir));

    // Calculate the up vector by cross-producting the direction vector with the right vector
    glm::vec3 up = glm::normalize(glm::cross(dir, right));

    // Calculate the translation vector from the camera position to the origin
    glm::vec3 translation = -pos;

    // Create the view matrix using the lookAt function from GLM
    glm::mat4 view = glm::lookAt(translation, dir, up);

    return view;
}
