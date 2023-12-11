#include <iostream>
#include <vector>
#include <GL/glew.h>

class ProgramPipeline {
public:
    ProgramPipeline(ShaderProgram& program) {
        // Set up the program pipeline using OpenGL functions
        GLuint programPipeline = glCreateProgramPipeline();
        glUseProgramStages(programPipeline, GL_VERTEX_SHADER_BIT, program.getVertexShader());
        glUseProgramStages(programPipeline, GL_FRAGMENT_SHADER_BIT, program.getFragmentShader());
        glUseProgramStages(programPipeline, GL_GEOMETRY_SHADER_BIT, program.getGeometryShader());
        glUseProgramStages(programPipeline, GL_TESS_CONTROL_SHADER_BIT, program.getTessControlShader());
        glUseProgramStages(programPipeline, GL_TESS_EVALUATION_SHADER_BIT, program.getTessEvaluationShader());
        glUseProgramStages(programPipeline, GL_COMPUTE_SHADER_BIT, program.getComputeShader());

        // Check for errors
        GLenum error = glGetError();
        if (error != GL_NO_ERROR) {
            std::cerr << "Error creating program pipeline: " << gluErrorString(error) << std::endl;
        }

        // Store the program pipeline object
        this->programPipeline = programPipeline;
    }

    ~ProgramPipeline() {
        // Delete the program pipeline object
        glDeleteProgramPipelines(1, &this->programPipeline);
    }

    void bind() {
        // Bind the program pipeline for use
        glBindProgramPipeline(this->programPipeline);
    }

    void unbind() {
        // Unbind the program pipeline
        glBindProgramPipeline(0);
    }

private:
    GLuint programPipeline;

    static GLbitfield convertShaderTypeToGLbitfield(ShaderType type) {
        switch (type) {
            case ShaderType::VERTEX:
                return GL_VERTEX_SHADER_BIT;
            case ShaderType::FRAGMENT:
                return GL_FRAGMENT_SHADER_BIT;
            case ShaderType::GEOMETRY:
                return GL_GEOMETRY_SHADER_BIT;
            case ShaderType::TESS_CONTROL:
                return GL_TESS_CONTROL_SHADER_BIT;
            case ShaderType::TESS_EVALUATION:
                return GL_TESS_EVALUATION_SHADER_BIT;
            case ShaderType::COMPUTE:
                return GL_COMPUTE_SHADER_BIT;
            default:
                return 0;
        }
    }
};
