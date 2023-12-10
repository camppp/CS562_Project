#include <opencv2/opencv.hpp>

template <typename T>
class SherlockDeallocator {
private:
    T* dataPtr;

public:
    // Constructor
    SherlockDeallocator(T* ptr) : dataPtr(ptr) {}

    // Custom deallocator
    void deallocate() {
        cv::Ptr<T> ptr(dataPtr);
        ptr.release();
    }

    // Method to release memory and reset the pointer
    void releaseMemory() {
        deallocate();
        dataPtr = nullptr;
    }

    // Destructor
    ~SherlockDeallocator() {
        releaseMemory();
    }
};
