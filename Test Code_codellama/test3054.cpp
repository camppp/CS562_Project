#include <vulkan/vulkan.h>
#include <vector>
#include <mutex>

class MemoryManager {
public:
    MemoryManager() {
        // Initialize Vulkan API
        VkResult result = vkInitialize();
        if (result != VK_SUCCESS) {
            throw std::runtime_error("Failed to initialize Vulkan API");
        }
    }

    ~MemoryManager() {
        // Clean up Vulkan API
        vkDestroy();
    }

    void* allocate(VkDeviceSize size, VkMemoryPropertyFlags flags) {
        // Lock mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Find a suitable memory block
        for (auto& block : memoryBlocks_) {
            if (block.size >= size && block.flags == flags) {
                // Split memory block into two parts
                VkDeviceSize splitSize = block.size - size;
                block.size = size;
                VkDeviceMemory newBlock = vkAllocateMemory(device_, size, flags);
                memoryBlocks_.push_back({newBlock, splitSize, flags});
                return newBlock;
            }
        }

        // Allocate new memory block
        VkDeviceMemory newBlock = vkAllocateMemory(device_, size, flags);
        memoryBlocks_.push_back({newBlock, size, flags});
        return newBlock;
    }

    void deallocate(VkDeviceMemory memory) {
        // Lock mutex to prevent concurrent access
        std::lock_guard<std::mutex> lock(mutex_);

        // Find memory block to deallocate
        for (auto it = memoryBlocks_.begin(); it != memoryBlocks_.end(); ++it) {
            if (it->memory == memory) {
                // Merge with adjacent memory blocks
                if (it != memoryBlocks_.begin()) {
                    auto prevIt = it;
                    --prevIt;
                    if (prevIt->flags == it->flags) {
                        prevIt->size += it->size;
                        memoryBlocks_.erase(it);
                        return;
                    }
                }
                if (it != memoryBlocks_.end() - 1) {
                    auto nextIt = it;
                    ++nextIt;
                    if (nextIt->flags == it->flags) {
                        nextIt->size += it->size;
                        memoryBlocks_.erase(it);
                        return;
                    }
                }
                // Deallocate memory block
                vkFreeMemory(device_, memory, nullptr);
                memoryBlocks_.erase(it);
                return;
            }
        }
    }

private:
    VkDevice device_;
    std::vector<MemoryBlock> memoryBlocks_;
    std::mutex mutex_;
};

struct MemoryBlock {
    VkDeviceMemory memory;
    VkDeviceSize size;
    VkMemoryPropertyFlags flags;
};
