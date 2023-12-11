void BindBuffer(int bufferType, int bufferID) {
    // Check if the buffer type is valid
    if (bufferType != GL_ARRAY_BUFFER && bufferType != GL_ELEMENT_ARRAY_BUFFER) {
        // If the buffer type is not valid, throw an error
        throw std::invalid_argument("Invalid buffer type");
    }

    // Bind the buffer based on the buffer type
    if (bufferType == GL_ARRAY_BUFFER) {
        glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    } else if (bufferType == GL_ELEMENT_ARRAY_BUFFER) {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID);
    }
}
