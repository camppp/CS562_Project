class Pool {
private:
    static const int POOL_SIZE = 10;
    int m_writeIndex;
    int m_readIndex;
    StreamData m_pool[POOL_SIZE];

public:
    Pool() : m_writeIndex(0), m_readIndex(0) {}

    void writeData(const char* data, int size) {
        if (m_writeIndex == m_readIndex - 1 || (m_writeIndex == POOL_SIZE - 1 && m_readIndex == 0)) {
            // Buffer is full, do nothing
            return;
        }

        m_pool[m_writeIndex].setData(data, size);
        m_writeIndex = (m_writeIndex + 1) % POOL_SIZE;
    }

    StreamData* takeData() {
        if (m_writeIndex == m_readIndex) {
            // Buffer is empty
            return nullptr;
        }

        StreamData* data = &m_pool[m_readIndex];
        m_readIndex = (m_readIndex + 1) % POOL_SIZE;
        return data;
    }
};