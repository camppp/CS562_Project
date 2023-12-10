void populateVertexBuffer(int pc, bool ok, int factor, int num_total_connectors) {
  if (ok) {
    const size_t quant = factor * num_total_connectors;
    VertexBuffer * vbo = I->G->ShaderMgr->newGPUBuffer<VertexBuffer>();
    std::vector<float> bufferData(quant);  // Create a buffer to hold the vertex data

    // Populate the buffer with appropriate data based on factor and total number of connectors
    for (size_t i = 0; i < quant; ++i) {
      // Populate the buffer with data based on factor and total number of connectors
      // Example: bufferData[i] = factor * num_total_connectors + i;
    }

    vbo->bufferData(bufferData);  // Populate the vertex buffer with the data
  }
}
