#include <memory>

class CustomMemoryManager {
    std::shared_ptr<void> storage;

    template<typename T>
    static void funcDeleter(void* mPtr) {
        static_cast<T*>(mPtr)->~T();
        operator delete(mPtr);
    }

public:
    template<typename T>
    T* allocate() {
        storage.reset(new T, funcDeleter<T>);
        return static_cast<T*>(storage.get());
    }

    template<typename T>
    void deallocate(T* ptr) {
        if (ptr == storage.get()) {
            storage.reset();
        }
    }
};
