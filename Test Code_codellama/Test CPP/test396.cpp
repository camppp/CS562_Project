class CircularBuffer {
private:
    char* buffer;
    int size;
    int read_ptr;
    int write_ptr;

public:
    CircularBuffer(int size) {
        this->size = size;
        this->buffer = new char[size];
        this->read_ptr = 0;
        this->write_ptr = 0;
    }

    ~CircularBuffer() {
        delete[] buffer;
    }

    int total_bytes() {
        return size;
    }

    int bytes_to_write() {
        return size - (write_ptr - read_ptr);
    }

    int bytes_to_read() {
        return write_ptr - read_ptr;
    }

    char* read_ptr() {
        return buffer + read_ptr;
    }

    char* write_ptr() {
        return buffer + write_ptr;
    }

    void read(char* buffer, int length) {
        if (length > bytes_to_read()) {
            length = bytes_to_read();
        }

        memcpy(buffer, read_ptr(), length);
        read_ptr += length;
    }

    void peek(char* buffer, int length, int index) {
        if (index < 0) {
            index = size + index;
        }

        if (index >= size) {
            index -= size;
        }

        memcpy(buffer, buffer + index, length);
    }
};
