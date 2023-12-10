#include <cstddef>
#include <stdexcept>
#include <memory>

template <typename T, size_t N>
class RingBuf {
public:
    RingBuf() : buffer(new T[N]), head(0), tail(0), size(0) {}

    void push_back(const T& value) {
        if (size == N) {
            head = (head + 1) % N;  // Overwrite the oldest element
        } else {
            size++;
        }
        buffer[tail] = value;
        tail = (tail + 1) % N;
    }

    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Buffer is empty");
        }
        head = (head + 1) % N;
        size--;
    }

    size_t size() const {
        return size;
    }

private:
    std::unique_ptr<T[]> buffer;
    size_t head;
    size_t tail;
    size_t size;
};

template <typename T, size_t N>
class DequeRingBuf {
public:
    DequeRingBuf() : head(0), tail(0), size(0) {}

    void push_back(const T& value) {
        if (size == N) {
            head = (head + 1) % N;  // Overwrite the oldest element
        } else {
            size++;
        }
        buffer[tail] = value;
        tail = (tail + 1) % N;
    }

    void pop_front() {
        if (size == 0) {
            throw std::out_of_range("Buffer is empty");
        }
        head = (head + 1) % N;
        size--;
    }

    size_t size() const {
        return size;
    }

private:
    T buffer[N];
    size_t head;
    size_t tail;
    size_t size;
};
