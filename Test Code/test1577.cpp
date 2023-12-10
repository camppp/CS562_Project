#include <iostream>
#include <GL/glew.h>

class Shader {
public:
    unsigned int compileSingleShader(const char* shaderStr, GLenum shaderEnum);
};

unsigned int Shader::compileSingleShader(const char* shaderStr, GLenum shaderEnum) {
    int success;
    char infoLog[512];

    unsigned int shader = glCreateShader(shaderEnum);
    glShaderSource(shader, 1, &shaderStr, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader compilation error: " << infoLog << std::endl;
        return 0;  // Return 0 to indicate compilation failure
    }

    return shader;  // Return the shader object ID if compilation is successful
}
