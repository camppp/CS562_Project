#include <iostream>
#include <vector>

class IndexBufferBase {
protected:
    std::vector<int> indices;

public:
    // Add an index to the buffer
    virtual void AddIndex(int index) = 0;

    // Get the index at a specific position
    virtual int GetIndex(int position) const = 0;

    // Get the total number of indices in the buffer
    virtual int GetSize() const = 0;

    // Resize the buffer to accommodate a new size
    virtual void Resize(int newSize) = 0;
};

class ConcreteIndexBuffer : public IndexBufferBase {
public:
    void AddIndex(int index) override {
        indices.push_back(index);
    }

    int GetIndex(int position) const override {
        if (position >= 0 && position < indices.size()) {
            return indices[position];
        }
        return -1; // Return -1 for out-of-bounds access
    }

    int GetSize() const override {
        return indices.size();
    }

    void Resize(int newSize) override {
        indices.resize(newSize);
    }
};

int main() {
    ConcreteIndexBuffer buffer;
    buffer.AddIndex(10);
    buffer.AddIndex(20);
    buffer.AddIndex(30);

    std::cout << "Indices: ";
    for (int i = 0; i < buffer.GetSize(); ++i) {
        std::cout << buffer.GetIndex(i) << " ";
    }
    std::cout << std::endl;

    buffer.Resize(5);
    std::cout << "Resized Indices: ";
    for (int i = 0; i < buffer.GetSize(); ++i) {
        std::cout << buffer.GetIndex(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
