#include <iostream>
#include <vector>

class MemoryManager {
private:
    std::vector<char> memory;
    std::vector<std::pair<size_t, size_t>> allocatedBlocks;

public:
    MemoryManager(size_t size) : memory(size, 0) {}

    char* allocate(size_t size) {
        for (size_t i = 0; i < memory.size(); ++i) {
            if (memory[i] == 0) {
                size_t j = i;
                while (j < memory.size() && memory[j] == 0 && j - i + 1 < size) {
                    ++j;
                }
                if (j - i + 1 == size) {
                    for (size_t k = i; k < j; ++k) {
                        memory[k] = 1;
                    }
                    allocatedBlocks.emplace_back(i, j - 1);
                    return &memory[i];
                }
                i = j;
            }
        }
        return nullptr;
    }

    void free(char* ptr) {
        size_t index = ptr - &memory[0];
        for (auto& block : allocatedBlocks) {
            if (block.first <= index && index <= block.second) {
                for (size_t i = block.first; i <= block.second; ++i) {
                    memory[i] = 0;
                }
                allocatedBlocks.erase(std::remove(allocatedBlocks.begin(), allocatedBlocks.end(), block), allocatedBlocks.end());
                break;
            }
        }
    }

    void defragment() {
        size_t freeIndex = 0;
        for (auto& block : allocatedBlocks) {
            size_t blockSize = block.second - block.first + 1;
            if (block.first != freeIndex) {
                for (size_t i = block.first; i <= block.second; ++i) {
                    memory[freeIndex] = memory[i];
                    memory[i] = 0;
                    ++freeIndex;
                }
                block.first = freeIndex - blockSize;
                block.second = freeIndex - 1;
            }
            freeIndex += blockSize;
        }
    }
};
