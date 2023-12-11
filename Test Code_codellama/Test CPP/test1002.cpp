#include <cstdint>

template<class Allocator>
class Stack {
    Allocator mAllocator;
    uint32_t mSize, mCapacity;
    T* mData;

public:
    // Constructor
    Stack() : mSize(0), mCapacity(10), mData(nullptr) {
        // Initialize the stack with initial capacity
    }

    // Destructor
    ~Stack() {
        // Release any allocated memory
        if (mData != nullptr) {
            mAllocator.deallocate(mData, mCapacity);
        }
    }

    // Add necessary member functions here
    void push(const T& value) {
        // Check if the stack is full
        if (mSize == mCapacity) {
            // Double the capacity if the stack is full
            mCapacity *= 2;
            // Allocate new memory for the stack
            mData = mAllocator.allocate(mCapacity);
            // Copy the old data to the new memory
            for (uint32_t i = 0; i < mSize; i++) {
                mData[i] = mData[i];
            }
        }
        // Add the new element to the top of the stack
        mData[mSize++] = value;
    }

    void pop() {
        // Check if the stack is empty
        if (mSize == 0) {
            // Throw an exception if the stack is empty
            throw std::runtime_error("Stack is empty");
        }
        // Remove the top element from the stack
        mSize--;
    }

    T& top() {
        // Check if the stack is empty
        if (mSize == 0) {
            // Throw an exception if the stack is empty
            throw std::runtime_error("Stack is empty");
        }
        // Return the top element of the stack
        return mData[mSize - 1];
    }

    uint32_t size() {
        // Return the current number of elements in the stack
        return mSize;
    }

    bool empty() {
        // Return true if the stack is empty, false otherwise
        return mSize == 0;
    }
};
