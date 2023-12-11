#include <cstring>  // For memcpy

class StreamData {
    // Assume StreamData implementation is available
};

class Pool {
private:
    static const int POOL_SIZE = 10;
    int m_writeIndex;
    int m_readIndex;
    StreamData m_pool[POOL_SIZE];

public:
    Pool() : m_writeIndex(0), m_readIndex(0) {}

    void writeData(const char* data, int size) {
        // Ensure data size does not exceed the size of StreamData
        size = std::min(size, sizeof(StreamData));

        // Copy data into the circular buffer at the current write index
        std::memcpy(&m_pool[m_writeIndex], data, size);

        // Increment the write index and wrap around if needed
        m_writeIndex = (m_writeIndex + 1) % POOL_SIZE;
    }

    StreamData* takeData() {
        // Check if the buffer is empty
        if (m_readIndex == m_writeIndex) {
            return nullptr; // Buffer is empty
        }

        // Get a pointer to the StreamData object at the current read index
        StreamData* data = &m_pool[m_readIndex];

        // Increment the read index and wrap around if needed
        m_readIndex = (m_readIndex + 1) % POOL_SIZE;

        return data;
    }
};
