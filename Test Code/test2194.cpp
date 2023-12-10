#include <string>
#include <sstream>

std::string generateOpenGLTextureSetup(int wrap, int minFilter, int magFilter, int internalFormat, int size) {
    std::stringstream openglCode;
    openglCode << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, " << wrap << ");\n";
    openglCode << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, " << minFilter << ");\n";
    openglCode << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, " << magFilter << ");\n";
    openglCode << "glTexStorage3D(GL_TEXTURE_3D, 7, " << internalFormat << ", " << size << ", " << size << ", " << size << ");\n";
    return openglCode.str();
}
