#include <unordered_map>
#include <string>
#include <GL/glew.h>

class Shader {
public:
    GLuint ID;
    // Other members and methods
};

class Texture {
public:
    GLuint ID;
    // Other members and methods
};

class ResourceManager {
private:
    std::unordered_map<std::string, Shader> Shaders;
    std::unordered_map<std::string, Texture> Textures;

public:
    void loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile) {
        // Implementation to load shader from file and store in Shaders map
        // ...
    }

    Texture& getTexture(const std::string& name) {
        return Textures[name];
    }

    void Clear() {
        // Properly delete all shaders
        for (auto& iter : Shaders)
            glDeleteProgram(iter.second.ID);
        Shaders.clear();

        // Properly delete all textures
        for (auto& iter : Textures)
            glDeleteTextures(1, &iter.second.ID);
        Textures.clear();
    }
};
