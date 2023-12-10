void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
{
    Bind();  // Assume Bind() is a function that binds the vertex array for subsequent operations

    const auto& elements = layout.GetElements();
    unsigned int offset = 0;

    for (unsigned int i = 0; i < elements.size(); i++)
    {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset);
        offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
    }

    buffer.Bind();  // Assume Bind() is a function that binds the vertex buffer for subsequent operations

    Unbind();  // Assume Unbind() is a function that unbinds the vertex array after operations
}
