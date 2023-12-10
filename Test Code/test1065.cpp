#include <vector>
#include <string>

class CircularBuffer {
public:
    CircularBuffer(int capacity) : capacity(capacity), size(0), head(0) {
        buffer.resize(capacity);
    }

    void push_back(const std::string& value) {
        buffer[head] = value;
        head = (head + 1) % capacity;
        if (size < capacity) {
            size++;
        }
    }

    std::string get(int index) {
        if (index < 0 || index >= size) {
            return "";
        }
        int actualIndex = (head - size + index + capacity) % capacity;
        return buffer[actualIndex];
    }

private:
    std::vector<std::string> buffer;
    int capacity;
    int size;
    int head;
};
