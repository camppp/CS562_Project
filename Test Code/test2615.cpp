template<typename T>
class CircularBuffer {
private:
    T* buffer;
    size_t capacity;
    size_t size;
    size_t front;
    size_t back;

public:
    CircularBuffer(size_t capacity) : capacity(capacity), size(0), front(0), back(0) {
        buffer = new T[capacity];
    }

    ~CircularBuffer() {
        delete[] buffer;
    }

    void push_back(T value) {
        if (size == capacity) {
            // Overwrite the oldest element in the buffer
            buffer[front] = value;
            front = (front + 1) % capacity;
        } else {
            // Add the new element to the buffer
            buffer[back] = value;
            back = (back + 1) % capacity;
            size++;
        }
    }

    T pop_front() {
        if (size == 0) {
            throw std::out_of_range("Buffer is empty");
        }

        T value = buffer[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    size_t size() {
        return size;
    }
};
