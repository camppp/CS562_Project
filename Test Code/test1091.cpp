#include <glm/glm.hpp>

class Wall {
private:
    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::mat4 m_modelMatrix;

public:
    Wall(glm::vec3 position, glm::vec3 scale) {
        m_position = position;
        m_scale = scale;

        m_modelMatrix = glm::translate(m_modelMatrix, position);
        m_modelMatrix = glm::scale(m_modelMatrix, scale);
    }

    float calculateVolume() {
        return m_scale.x * m_scale.y * m_scale.z;
    }
};
