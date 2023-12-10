// Include necessary header files for the custom vector and matrix library
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <iostream>

int main() {
    // Define instances of vec2, vec3, vec4, and mat4 using the type aliases
    vec2 v2(1.0f, 2.0f);
    vec3 v3(1.0f, 2.0f, 3.0f);
    vec4 v4(1.0f, 2.0f, 3.0f, 4.0f);
    mat4 m4(1.0f);  // Initialize mat4 as an identity matrix

    // Perform basic operations
    vec2 result_v2 = v2 * 2.0f;  // Scalar multiplication
    vec3 result_v3 = v3 + vec3(1.0f, 1.0f, 1.0f);  // Vector addition
    vec4 result_v4 = v4 * 2.0f;  // Scalar multiplication
    mat4 result_m4 = m4 * m4;  // Matrix multiplication

    // Output the results
    std::cout << "Result of vec2 scalar multiplication: (" << result_v2.x << ", " << result_v2.y << ")" << std::endl;
    std::cout << "Result of vec3 vector addition: (" << result_v3.x << ", " << result_v3.y << ", " << result_v3.z << ")" << std::endl;
    std::cout << "Result of vec4 scalar multiplication: (" << result_v4.x << ", " << result_v4.y << ", " << result_v4.z << ", " << result_v4.w << ")" << std::endl;
    std::cout << "Result of mat4 matrix multiplication: " << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << result_m4[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
