#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
public:
    Transform(const mat4& matrix) {
        glm::vec3 scale;
        glm::quat rotation;
        glm::vec3 position;

        glm::decompose(matrix, scale, rotation, position, glm::vec3(0, 0, 0), glm::vec4(0, 0, 0, 1));

        this->scale = scale;
        this->rotation = rotation;
        this->position = position;
    }

    glm::vec3 getScale() const {
        return scale;
    }

    glm::quat getRotation() const {
        return rotation;
    }

    glm::vec3 getPosition() const {
        return position;
    }

private:
    glm::vec3 scale;
    glm::quat rotation;
    glm::vec3 position;
};
