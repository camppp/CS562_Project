#include <iostream>
#include <glm/glm.hpp>

int main() {
    // Create instances of vec2, vec3, vec4, and mat4
    glm::vec2 v2 = glm::vec2(1.0f, 2.0f);
    glm::vec3 v3 = glm::vec3(3.0f, 4.0f, 5.0f);
    glm::vec4 v4 = glm::vec4(6.0f, 7.0f, 8.0f, 9.0f);
    glm::mat4 m4 = glm::mat4(1.0f, 2.0f, 3.0f, 4.0f,
                              5.0f, 6.0f, 7.0f, 8.0f,
                              9.0f, 10.0f, 11.0f, 12.0f,
                              13.0f, 14.0f, 15.0f, 16.0f);

    // Perform vector addition
    glm::vec2 v2_add = v2 + v3;
    std::cout << "v2 + v3 = " << v2_add << std::endl;

    // Perform scalar multiplication
    glm::vec2 v2_scale = v2 * 2.0f;
    std::cout << "v2 * 2.0f = " << v2_scale << std::endl;

    // Perform matrix multiplication
    glm::mat4 m4_mul = m4 * v4;
    std::cout << "m4 * v4 = " << m4_mul << std::endl;

    return 0;
}
