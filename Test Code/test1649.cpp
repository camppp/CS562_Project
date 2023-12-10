#include <vector>

class IndicesBufferManager {
private:
    std::vector<unsigned> indicesBuffer;

public:
    // Method to initialize the indices buffer with a specified size
    void initializeBuffer(size_t size) {
        indicesBuffer.resize(size);
    }

    // Method to add an index to the buffer
    void addIndex(unsigned index) {
        indicesBuffer.push_back(index);
    }

    // Method to retrieve the index at a specified position in the buffer
    unsigned getIndexAtPosition(size_t position) {
        if (position < indicesBuffer.size()) {
            return indicesBuffer[position];
        } else {
            // Handle out of range error
            return 0; // Assuming 0 as an invalid index
        }
    }

    // Method to clear the buffer
    void clearBuffer() {
        indicesBuffer.clear();
    }
};
