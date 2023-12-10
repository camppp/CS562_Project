VertexArray::VertexArray(ag::span<VertexAttribute> attribs) {
    // Initialize the vertex array object
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    // Iterate over the vertex attributes and configure them
    for (const VertexAttribute& attrib : attribs) {
        // Set the attribute size, type, stride, and offset
        glVertexAttribPointer(attrib.size, attrib.type, attrib.stride, attrib.offset);
        glEnableVertexAttribArray(attrib.size);
    }

    // Unbind the vertex array object
    glBindVertexArray(0);
}
