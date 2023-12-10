#include <memory>

class CustomMemoryManager {
public:
    template <typename T>
    T* allocate() {
        // Allocate memory for an object of type T
        std::shared_ptr<T> storage = std::shared_ptr<T>(new T(), funcDeleter);
        return storage.get();
    }

    template <typename T>
    void deallocate(T* ptr) {
        // Deallocate the memory pointed to by ptr and properly destruct the object
        std::shared_ptr<T> storage = std::shared_ptr<T>(ptr, funcDeleter);
        storage.reset();
    }

private:
    // Custom deleter function
    static void funcDeleter(void* ptr) {
        delete static_cast<T*>(ptr);
    }
};
