class CircularBuffer {
private:
    int capacity;
    int readPos;
    int writePos;
    int* buffer;

public:
    CircularBuffer(int capacity) {
        this->capacity = capacity;
        this->readPos = 0;
        this->writePos = 0;
        this->buffer = new int[capacity];
    }

    void write(int value) {
        if (writePos == capacity) {
            // Buffer is full, overwrite the oldest value
            buffer[readPos] = value;
            readPos = (readPos + 1) % capacity;
        } else {
            // Buffer is not full, write the value
            buffer[writePos] = value;
            writePos = (writePos + 1) % capacity;
        }
    }

    int read() {
        if (readPos == writePos) {
            // Buffer is empty, return -1
            return -1;
        } else {
            // Buffer is not empty, return the oldest value
            int value = buffer[readPos];
            readPos = (readPos + 1) % capacity;
            return value;
        }
    }
};
