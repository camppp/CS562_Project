#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class TransformationLibrary {
public:
    glm::mat4 transformationMatrix;

    void rotateXDeg(float degrees) {
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(degrees), glm::vec3(1.0f, 0.0f, 0.0f));
    }

    void rotateYDeg(float degrees) {
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(degrees), glm::vec3(0.0f, 1.0f, 0.0f));
    }

    void rotateZDeg(float degrees) {
        transformationMatrix = glm::rotate(transformationMatrix, glm::radians(degrees), glm::vec3(0.0f, 0.0f, 1.0f));
    }

    void rotateXRad(float radians) {
        transformationMatrix = glm::rotate(transformationMatrix, radians, glm::vec3(1.0f, 0.0f, 0.0f));
    }

    void rotateYRad(float radians) {
        transformationMatrix = glm::rotate(transformationMatrix, radians, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    void rotateZRad(float radians) {
        transformationMatrix = glm::rotate(transformationMatrix, radians, glm::vec3(0.0f, 0.0f, 1.0f));
    }
};
