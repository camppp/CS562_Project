void populateVertexBuffer(int pc, bool ok, int factor, int num_total_connectors) {
    // Create a new vertex buffer if all operations were successful
    if (ok) {
        // Calculate the size of the vertex buffer data
        int vbo_size = factor * num_total_connectors;

        // Create a new vertex buffer
        VertexBuffer vbo(vbo_size);

        // Populate the vertex buffer with data
        for (int i = 0; i < vbo_size; i++) {
            // Calculate the position of the current vertex
            int pos = pc + i * factor;

            // Set the position of the current vertex
            vbo.setPosition(pos);
        }
    }
}
