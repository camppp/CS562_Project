#include <iostream>
#include <vector>

class IndexBufferBase {
protected:
    std::vector<int> indices;

public:
    // Add an index to the buffer
    virtual void AddIndex(int index) {
        indices.push_back(index);
    }

    // Get the index at a specific position
    virtual int GetIndex(int position) const {
        return indices[position];
    }

    // Get the total number of indices in the buffer
    virtual int GetSize() const {
        return indices.size();
    }

    // Resize the buffer to accommodate a new size
    virtual void Resize(int newSize) {
        indices.resize(newSize);
    }
};

// Concrete derived class that inherits from IndexBufferBase
class IndexBuffer : public IndexBufferBase {
public:
    // Add an index to the buffer
    void AddIndex(int index) override {
        indices.push_back(index);
    }

    // Get the index at a specific position
    int GetIndex(int position) const override {
        return indices[position];
    }

    // Get the total number of indices in the buffer
    int GetSize() const override {
        return indices.size();
    }

    // Resize the buffer to accommodate a new size
    void Resize(int newSize) override {
        indices.resize(newSize);
    }
};

int main() {
    IndexBuffer buffer;

    // Add some indices to the buffer
    buffer.AddIndex(1);
    buffer.AddIndex(2);
    buffer.AddIndex(3);

    // Get the indices at specific positions
    std::cout << buffer.GetIndex(0) << std::endl; // Output: 1
    std::cout << buffer.GetIndex(1) << std::endl; // Output: 2
    std::cout << buffer.GetIndex(2) << std::endl; // Output: 3

    // Get the total number of indices in the buffer
    std::cout << buffer.GetSize() << std::endl; // Output: 3

    // Resize the buffer to accommodate a new size
    buffer.Resize(5);

    // Add some more indices to the buffer
    buffer.AddIndex(4);
    buffer.AddIndex(5);
    buffer.AddIndex(6);

    // Get the indices at specific positions
    std::cout << buffer.GetIndex(0) << std::endl; // Output: 1
    std::cout << buffer.GetIndex(1) << std::endl; // Output: 2
    std::cout << buffer.GetIndex(2) << std::endl; // Output: 3
    std::cout << buffer.GetIndex(3) << std::endl; // Output: 4
    std::cout << buffer.GetIndex(4) << std::endl; // Output: 5
    std::cout << buffer.GetIndex(5) << std::endl; // Output: 6

    // Get the total number of indices in the buffer
    std::cout << buffer.GetSize() << std::endl; // Output: 6

    return 0;
}
