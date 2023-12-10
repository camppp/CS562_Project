void Pool::writeData(const char* data, int size) {
    // Check if the buffer is full
    if (m_writeIndex == POOL_SIZE) {
        // Wrap around to the beginning of the buffer
        m_writeIndex = 0;
    }

    // Copy the data into the buffer
    memcpy(&m_pool[m_writeIndex], data, size);

    // Increment the write index
    m_writeIndex++;
}

StreamData* Pool::takeData() {
    // Check if the buffer is empty
    if (m_writeIndex == m_readIndex) {
        // Return a null pointer
        return nullptr;
    }

    // Get the data at the current read index
    StreamData* data = &m_pool[m_readIndex];

    // Increment the read index
    m_readIndex++;

    // Wrap around to the beginning of the buffer if necessary
    if (m_readIndex == POOL_SIZE) {
        m_readIndex = 0;
    }

    return data;
}
