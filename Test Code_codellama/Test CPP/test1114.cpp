void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
{
    // Check if the buffer is already associated with a vertex array
    if (buffer.GetVertexArray() != nullptr)
    {
        // If the buffer is already associated with a vertex array, throw an exception
        throw std::runtime_error("Vertex buffer is already associated with a vertex array");
    }

    // Set the vertex array of the buffer to this vertex array
    buffer.SetVertexArray(this);

    // Add the buffer to the vertex array
    m_Buffers.push_back(buffer);

    // Set the layout of the buffer
    buffer.SetLayout(layout);
}
