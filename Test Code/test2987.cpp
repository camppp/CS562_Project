#include <array>
#include <glm/vec2.hpp>

float calculateSpaceshipArea(const std::array<glm::vec2, 24>& positions) {
    float area = 0.0f;
    for (int i = 0; i < positions.size(); i += 2) {
        glm::vec2 p1 = positions[i];
        glm::vec2 p2 = positions[i + 1];
        glm::vec2 p3 = positions[i + 2];
        area += glm::triangleArea(p1, p2, p3);
    }
    return area;
}
