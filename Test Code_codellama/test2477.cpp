// Shader1.h
#include "rend_shader.h"

class Shader1 : public rend_shader
{
public:
    Shader1(const char* name, const char* vertexShader, const char* fragmentShader)
        : rend_shader(name, vertexShader, fragmentShader)
    {
        // Initialize the shader program
        mProgram = glCreateProgram();
        glAttachShader(mProgram, mVertexShader);
        glAttachShader(mProgram, mFragmentShader);
        glLinkProgram(mProgram);
        glUseProgram(mProgram);
    }

    virtual ~Shader1()
    {
        glDeleteProgram(mProgram);
    }

    void SetUniform(const char* name, float value)
    {
        glUniform1f(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, int value)
    {
        glUniform1i(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, const vec3& value)
    {
        glUniform3f(glGetUniformLocation(mProgram, name), value.x, value.y, value.z);
    }

    void SetUniform(const char* name, const mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(mProgram, name), 1, GL_FALSE, value.data());
    }

private:
    GLuint mProgram;
};

// Shader2.h
#include "rend_shader.h"

class Shader2 : public rend_shader
{
public:
    Shader2(const char* name, const char* vertexShader, const char* fragmentShader)
        : rend_shader(name, vertexShader, fragmentShader)
    {
        // Initialize the shader program
        mProgram = glCreateProgram();
        glAttachShader(mProgram, mVertexShader);
        glAttachShader(mProgram, mFragmentShader);
        glLinkProgram(mProgram);
        glUseProgram(mProgram);
    }

    virtual ~Shader2()
    {
        glDeleteProgram(mProgram);
    }

    void SetUniform(const char* name, float value)
    {
        glUniform1f(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, int value)
    {
        glUniform1i(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, const vec3& value)
    {
        glUniform3f(glGetUniformLocation(mProgram, name), value.x, value.y, value.z);
    }

    void SetUniform(const char* name, const mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(mProgram, name), 1, GL_FALSE, value.data());
    }

private:
    GLuint mProgram;
};

// psrcsub.h
#include "rend_shader.h"

class psrcsub
{
public:
    psrcsub(const char* name, const char* vertexShader, const char* fragmentShader)
        : rend_shader(name, vertexShader, fragmentShader)
    {
        // Initialize the shader program
        mProgram = glCreateProgram();
        glAttachShader(mProgram, mVertexShader);
        glAttachShader(mProgram, mFragmentShader);
        glLinkProgram(mProgram);
        glUseProgram(mProgram);
    }

    virtual ~psrcsub()
    {
        glDeleteProgram(mProgram);
    }

    void SetUniform(const char* name, float value)
    {
        glUniform1f(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, int value)
    {
        glUniform1i(glGetUniformLocation(mProgram, name), value);
    }

    void SetUniform(const char* name, const vec3& value)
    {
        glUniform3f(glGetUniformLocation(mProgram, name), value.x, value.y, value.z);
    }

    void SetUniform(const char* name, const mat4& value)
    {
        glUniformMatrix4fv(glGetUniformLocation(mProgram, name), 1, GL_FALSE, value.data());
    }

    int GetNumPolys()
    {
        // Calculate the number of triangles in the source geometry
        int numPolys = 0;
        for (int i = 0; i < mNumVertices; i += 3)
        {
            numPolys++;
        }
        return numPolys;
    }

private:
    GLuint mProgram;
    int mNumVertices;
};

// main.cpp
#include "Shader1.h"
#include "Shader2.h"
#include "psrcsub.h"

int main()
{
    // Create a shader object
    Shader1 shader1("shader1", "vertexShader.glsl", "fragmentShader.glsl");
    Shader2 shader2("shader2", "vertexShader.glsl", "fragmentShader.glsl");

    // Create a source mesh object
    psrcsub srcsub("srcsub", "vertexShader.glsl", "fragmentShader.glsl");

    // Set the number of triangles in the source geometry
    int numTriangles = srcsub.GetNumPolys();

    // Set the number of triangles in the output geometry
    outsub.miNumTriangles = numTriangles;

    // Render the scene
    while (1)
    {
        // Update the scene
        // ...

        // Render the scene
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(shader1.mProgram);
        glBindVertexArray(srcsub.mVAO);
        glDrawArrays(GL_TRIANGLES, 0, numTriangles * 3);
        glUseProgram(shader2.mProgram);
        glBindVertexArray(outsub.mVAO);
        glDrawArrays(GL_TRIANGLES, 0, outsub.miNumTriangles * 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
