#include <iostream>
#include <cstring>

struct StreamData {
    char frame[100];  // Assuming a maximum frame size of 100 bytes
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
        memcpy(m_pool[m_writeIndex].frame, data, size);

        if (++m_writeIndex >= POOL_SIZE) m_writeIndex = 0;
    }

    StreamData* takeData() {
        StreamData* data = nullptr;

        if (m_readIndex != m_writeIndex) {
            data = &m_pool[m_readIndex];
            if (++m_readIndex >= POOL_SIZE) m_readIndex = 0;
        }

        return data;
    }
};

int main() {
    Pool buffer;

    // Write data into the circular buffer
    buffer.writeData("Frame 1", 7);
    buffer.writeData("Frame 2", 7);
    buffer.writeData("Frame 3", 7);

    // Read and print data from the circular buffer
    StreamData* data;
    while ((data = buffer.takeData()) != nullptr) {
        std::cout << "Data: " << data->frame << std::endl;
    }

    return 0;
}
