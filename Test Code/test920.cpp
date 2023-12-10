#include <GL/glew.h>

class ShaderProgram {
    // Assume the existence of the ShaderProgram class with appropriate members and functions
};

class ProgramPipeline {
private:
    GLuint mPipelineID;

    static GLbitfield convertShaderTypeToGLbitfield(ShaderType type) {
        // Implement the conversion logic based on the ShaderType enum
        // Example:
        switch (type) {
            case ShaderType::Vertex:
                return GL_VERTEX_SHADER_BIT;
            case ShaderType::Fragment:
                return GL_FRAGMENT_SHADER_BIT;
            // Handle other shader types
            default:
                return 0;
        }
    }

public:
    ProgramPipeline(const ShaderProgram& shaderProgram) {
        glGenProgramPipelines(1, &this->mPipelineID);
        GLbitfield programStage = convertShaderTypeToGLbitfield(shaderProgram.Type());
        glUseProgramStages(this->mPipelineID, programStage, shaderProgram.ID());
    }

    void bind() {
        glBindProgramPipeline(mPipelineID);
    }

    void unbind() {
        glBindProgramPipeline(0);
    }

    // Add other member functions as needed

    ~ProgramPipeline() {
        glDeleteProgramPipelines(1, &mPipelineID);
    }
};
