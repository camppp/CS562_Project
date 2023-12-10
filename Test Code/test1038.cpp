class MemoryManager {
public:
    static void* allocate(size_t size) {
        void* ptr = malloc(size);
        if (ptr == nullptr) {
            throw std::runtime_error("Failed to allocate memory");
        }
        return ptr;
    }

    static void deallocate(void* ptr) {
        free(ptr);
    }
};

class MyClass {
public:
    MyClass() {
        data = MemoryManager::allocate(sizeof(int));
    }

    ~MyClass() {
        MemoryManager::deallocate(data);
    }

private:
    int* data;
};

struct MyStruct {
    MyStruct() {
        data = MemoryManager::allocate(sizeof(int));
    }

    ~MyStruct() {
        MemoryManager::deallocate(data);
    }

private:
    int* data;
};

int main() {
    MyClass* obj = new MyClass();
    MyStruct* structObj = new MyStruct();

    delete obj;
    delete structObj;

    return 0;
}
