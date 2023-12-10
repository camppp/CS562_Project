#include <iostream>

class CircularBuffer {
private:
    int* buffer;
    int capacity;
    int readIndex;
    int writeIndex;
    bool full;

public:
    CircularBuffer(int capacity) : capacity(capacity), readIndex(0), writeIndex(0), full(false) {
        buffer = new int[capacity];
    }

    ~CircularBuffer() {
        delete[] buffer;
    }

    void write(int value) {
        buffer[writeIndex] = value;
        writeIndex = (writeIndex + 1) % capacity;
        if (full) {
            readIndex = (readIndex + 1) % capacity;
        }
        if (writeIndex == readIndex) {
            full = true;
        }
    }

    int read() {
        if (readIndex == writeIndex && !full) {
            return -1;  // Buffer is empty
        }
        int value = buffer[readIndex];
        readIndex = (readIndex + 1) % capacity;
        full = false;
        return value;
    }
};

int main() {
    CircularBuffer buffer(5);
    buffer.write(1);
    buffer.write(2);
    buffer.write(3);
    std::cout << buffer.read() << std::endl;  // Output: 1
    buffer.write(4);
    buffer.write(5);
    buffer.write(6);
    std::cout << buffer.read() << std::endl;  // Output: 2
    std::cout << buffer.read() << std::endl;  // Output: 3
    std::cout << buffer.read() << std::endl;  // Output: 4
    std::cout << buffer.read() << std::endl;  // Output: 5
    std::cout << buffer.read() << std::endl;  // Output: 6
    std::cout << buffer.read() << std::endl;  // Output: -1 (buffer is empty)
    return 0;
}
