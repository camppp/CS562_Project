#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TransformationLibrary {
public:
    void rotateXDeg(float degrees) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(degrees), glm::vec3(1.0f, 0.0f, 0.0f));
        // Apply the rotation matrix to the object
    }

    void rotateYDeg(float degrees) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(degrees), glm::vec3(0.0f, 1.0f, 0.0f));
        // Apply the rotation matrix to the object
    }

    void rotateZDeg(float degrees) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(degrees), glm::vec3(0.0f, 0.0f, 1.0f));
        // Apply the rotation matrix to the object
    }

    void rotateXRad(float radians) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(1.0f, 0.0f, 0.0f));
        // Apply the rotation matrix to the object
    }

    void rotateYRad(float radians) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 1.0f, 0.0f));
        // Apply the rotation matrix to the object
    }

    void rotateZRad(float radians) {
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), radians, glm::vec3(0.0f, 0.0f, 1.0f));
        // Apply the rotation matrix to the object
    }
};
