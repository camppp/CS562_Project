#include <iostream>
#include <cstring>

class CircularBuffer {
private:
    char* buffer;
    int size;
    int readIndex;
    int writeIndex;
    int totalBytes;

public:
    CircularBuffer(int bufferSize) : size(bufferSize), readIndex(0), writeIndex(0), totalBytes(0) {
        buffer = new char[size];
    }

    ~CircularBuffer() {
        delete[] buffer;
    }

    void peek(char* buffer, int length, int index) {
        for (int i = 0; i < length; i++) {
            buffer[i] = this->buffer[(index + i) % size];
        }
    }

    int total_bytes() {
        return totalBytes;
    }

    int bytes_to_write() {
        return size - totalBytes;
    }

    int bytes_to_read() {
        return totalBytes;
    }

    char* read_ptr() {
        return &buffer[readIndex];
    }

    char* write_ptr() {
        return &buffer[writeIndex];
    }

    void read(char* buffer, int length) {
        for (int i = 0; i < length; i++) {
            buffer[i] = this->buffer[readIndex];
            readIndex = (readIndex + 1) % size;
            totalBytes--;
        }
    }

    void write(const char* data, int length) {
        for (int i = 0; i < length; i++) {
            buffer[writeIndex] = data[i];
            writeIndex = (writeIndex + 1) % size;
            totalBytes++;
        }
    }
};

int main() {
    const int small = 25;
    CircularBuffer mb(4 * small);

    char buffer[100];
    mb.peek(buffer, 50, 0);
    mb.peek(buffer + 50, 50, 50);
    for (int i = 0; i < 100; i++) {
        if (i < 50) {
            std::cout << buffer[i];
        } else {
            std::cout << buffer[i - 50];
        }
    }

    std::cout << std::endl;

    std::cout << "Total Bytes: " << mb.total_bytes() << std::endl;
    std::cout << "Bytes to Write: " << mb.bytes_to_write() << std::endl;
    std::cout << "Bytes to Read: " << mb.bytes_to_read() << std::endl;
    std::cout << "Read Pointer: " << (void*)mb.read_ptr() << std::endl;
    std::cout << "Write Pointer: " << (void*)mb.write_ptr() << std::endl;

    char buffer2[100];
    mb.read(buffer2, 100);

    return 0;
}
