class VertexArray {
public:
    VertexArray(ag::span<VertexAttribute> attribs) {
        // Calculate the total stride required for the vertex attributes
        int totalStride = 0;
        for (const auto& attrib : attribs) {
            totalStride += attrib.size * getSizeOfType(attrib.type);
        }

        // Generate and bind the vertex array object
        glGenVertexArrays(1, &mVertexArrayID);
        glBindVertexArray(mVertexArrayID);

        // Enable and configure each vertex attribute
        int offset = 0;
        for (size_t i = 0; i < attribs.size(); ++i) {
            const auto& attrib = attribs[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, attrib.size, attrib.type, GL_FALSE, totalStride, reinterpret_cast<void*>(offset));
            offset += attrib.size * getSizeOfType(attrib.type);
        }

        // Unbind the vertex array
        glBindVertexArray(0);
    }

    // Other member functions and data members can be assumed to exist but are not relevant to this problem.

private:
    GLuint mVertexArrayID;

    int getSizeOfType(int type) {
        switch (type) {
            case GL_FLOAT:
                return sizeof(GLfloat);
            case GL_INT:
                return sizeof(GLint);
            // Add cases for other supported data types as needed
            default:
                throw std::invalid_argument("Unsupported data type");
        }
    }
};
