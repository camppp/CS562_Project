#include <unordered_map>
#include <string>
#include <iostream>

class Shader {
public:
    Shader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile) {
        // Load the shader program from the specified files
        // and store the resulting shader program ID in the ID member
    }

    ~Shader() {
        // Delete the shader program ID when the shader is destroyed
        glDeleteProgram(ID);
    }

    GLuint ID;
};

class Texture {
public:
    Texture(const std::string& textureFile) {
        // Load the texture from the specified file
        // and store the resulting texture ID in the ID member
    }

    ~Texture() {
        // Delete the texture ID when the texture is destroyed
        glDeleteTexture(ID);
    }

    GLuint ID;
};

class ResourceManager {
public:
    ResourceManager() {
        // Initialize the shaders and textures maps
        shaders = std::unordered_map<std::string, Shader>();
        textures = std::unordered_map<std::string, Texture>();
    }

    ~ResourceManager() {
        // Clear all shaders and textures when the resource manager is destroyed
        Clear();
    }

    void loadShaderFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile, const std::string& geometryShaderFile) {
        // Load the shader program from the specified files
        // and store it in the shaders map
        Shader shader(vertexShaderFile, fragmentShaderFile, geometryShaderFile);
        shaders[shader.ID] = shader;
    }

    Texture getTexture(const std::string& textureName) {
        // Retrieve the texture with the specified name from the textures map
        // and return it
        return textures[textureName];
    }

    void Clear() {
        // Delete all shaders and textures from memory
        for (auto& shader : shaders) {
            glDeleteProgram(shader.second.ID);
        }
        shaders.clear();

        for (auto& texture : textures) {
            glDeleteTexture(texture.second.ID);
        }
        textures.clear();
    }

private:
    std::unordered_map<std::string, Shader> shaders;
    std::unordered_map<std::string, Texture> textures;
};
