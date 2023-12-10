#include <array>
#include <glm/glm.hpp>

float calculateTriangleArea(const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3) {
    return 0.5f * std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}

float calculateSpaceshipArea(const std::array<glm::vec2, 24>& positions) {
    float totalArea = 0.0f;

    // Calculate the area of each triangle formed by consecutive vertices
    for (size_t i = 0; i < positions.size() - 2; i++) {
        totalArea += calculateTriangleArea(positions[0], positions[i + 1], positions[i + 2]);
    }

    return totalArea;
}
