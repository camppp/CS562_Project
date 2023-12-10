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
        memory = new MemoryBlock;
        memory->size = totalSize;
        memory->free = true;
        memory->next = nullptr;
    }

    void* allocate(size_t size) {
        MemoryBlock* current = memory;
        while (current != nullptr) {
            if (current->free && current->size >= size) {
                if (current->size > size + sizeof(MemoryBlock)) {
                    MemoryBlock* newBlock = reinterpret_cast<MemoryBlock*>(reinterpret_cast<char*>(current) + size + sizeof(MemoryBlock));
                    newBlock->size = current->size - size - sizeof(MemoryBlock);
                    newBlock->free = true;
                    newBlock->next = current->next;
                    current->size = size;
                    current->free = false;
                    current->next = newBlock;
                } else {
                    current->free = false;
                }
                return reinterpret_cast<void*>(current + 1);
            }
            current = current->next;
        }
        return nullptr;
    }

    void deallocate(void* ptr) {
        if (ptr == nullptr) {
            return;
        }
        MemoryBlock* block = reinterpret_cast<MemoryBlock*>(ptr) - 1;
        block->free = true;
        coalesceFreeBlocks();
    }

    void displayMemoryStatus() {
        MemoryBlock* current = memory;
        while (current != nullptr) {
            std::cout << "Block size: " << current->size << ", Free: " << (current->free ? "Yes" : "No") << std::endl;
            current = current->next;
        }
    }

private:
    MemoryBlock* memory;

    void coalesceFreeBlocks() {
        MemoryBlock* current = memory;
        while (current != nullptr && current->next != nullptr) {
            if (current->free && current->next->free) {
                current->size += current->next->size + sizeof(MemoryBlock);
                current->next = current->next->next;
            } else {
                current = current->next;
            }
        }
    }
};
