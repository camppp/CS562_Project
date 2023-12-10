#include <cstddef>
#include <iostream>

struct MemoryBlock {
    size_t size;
    bool free;
    MemoryBlock* next;
};

class CustomAllocator {
public:
    CustomAllocator(size_t totalSize) {
        memory = new MemoryBlock[totalSize];
        for (size_t i = 0; i < totalSize; i++) {
            memory[i].size = totalSize - i;
            memory[i].free = true;
            memory[i].next = &memory[i + 1];
        }
        memory[totalSize - 1].next = nullptr;
    }

    void* allocate(size_t size) {
        MemoryBlock* current = memory;
        while (current != nullptr) {
            if (current->free && current->size >= size) {
                current->free = false;
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deallocate(void* ptr) {
        MemoryBlock* block = (MemoryBlock*)ptr;
        block->free = true;
    }

    void displayMemoryStatus() {
        MemoryBlock* current = memory;
        while (current != nullptr) {
            if (current->free) {
                std::cout << "Free block of size " << current->size << std::endl;
            } else {
                std::cout << "Allocated block of size " << current->size << std::endl;
            }
            current = current->next;
        }
    }

private:
    MemoryBlock* memory;
};
