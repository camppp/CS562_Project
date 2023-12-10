#include <GL/glew.h>

class Shader {
public:
    unsigned int compileSingleShader(const char* shaderStr, GLenum shaderEnum) {
        // Create a shader object
        unsigned int shaderID = glCreateShader(shaderEnum);

        // Set the source code for the shader
        glShaderSource(shaderID, 1, &shaderStr, NULL);

        // Compile the shader
        glCompileShader(shaderID);

        // Check for compilation errors
        int success;
        char infoLog[512];
        glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
            std::cout << "Error compiling shader: " << infoLog << std::endl;
            return 0;
        }

        return shaderID;
    }
};
