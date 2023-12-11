class IndicesBufferManager {
public:
    IndicesBufferManager(unsigned size) {
        mIndicesBuffer = new unsigned[size];
        mSize = size;
    }

    ~IndicesBufferManager() {
        delete[] mIndicesBuffer;
    }

    void addIndex(unsigned index) {
        if (mSize == 0) {
            mIndicesBuffer = new unsigned[mSize];
        }
        mIndicesBuffer[mSize++] = index;
    }

    unsigned getIndex(unsigned position) {
        return mIndicesBuffer[position];
    }

    void clear() {
        mSize = 0;
    }

private:
    unsigned* mIndicesBuffer;
    unsigned mSize;
};
