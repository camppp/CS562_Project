#include <cstdint>

template<class Allocator>
class Stack {
    Allocator mAllocator;
    uint32_t mSize, mCapacity;
    T* mData;

public:
    // Constructor
    Stack() : mSize(0), mCapacity(10), mData(mAllocator.allocate(10)) {
        // Initialize the stack with initial capacity
    }

    // Destructor
    ~Stack() {
        mAllocator.deallocate(mData, mCapacity);
    }

    void push(const T& value) {
        if (mSize == mCapacity) {
            mCapacity *= 2;
            T* newData = mAllocator.allocate(mCapacity);
            for (uint32_t i = 0; i < mSize; ++i) {
                newData[i] = mData[i];
            }
            mAllocator.deallocate(mData, mSize);
            mData = newData;
        }
        mData[mSize++] = value;
    }

    void pop() {
        if (mSize > 0) {
            --mSize;
        }
    }

    T& top() {
        return mData[mSize - 1];
    }

    uint32_t size() {
        return mSize;
    }

    bool empty() {
        return mSize == 0;
    }
};
