std::string generateOpenGLTextureSetup(int wrap, int minFilter, int magFilter, int internalFormat, int size) {
    std::stringstream ss;
    ss << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, " << wrap << ");" << std::endl;
    ss << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, " << minFilter << ");" << std::endl;
    ss << "glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, " << magFilter << ");" << std::endl;
    ss << "glTexStorage3D(GL_TEXTURE_3D, 7, " << internalFormat << ", " << size << ", " << size << ", " << size << ");" << std::endl;
    return ss.str();
}
