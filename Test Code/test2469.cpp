#include <iostream>
#include <vector>
#include <algorithm>

class MemoryManager
{
private:
    struct MemoryBlock
    {
        size_t size;
        bool free;
    };

    std::vector<MemoryBlock> memoryRegion;

public:
    void initialize(size_t regionSize)
    {
        memoryRegion.clear();
        memoryRegion.push_back({regionSize, true});
    }

    void* allocate(size_t blockSize)
    {
        for (auto& block : memoryRegion)
        {
            if (block.free && block.size >= blockSize)
            {
                block.free = false;
                if (block.size > blockSize)
                {
                    memoryRegion.insert(std::next(memoryRegion.begin()), {block.size - blockSize, true});
                    block.size = blockSize;
                }
                return &block;
            }
        }
        return nullptr; // Memory allocation failed
    }

    void deallocate(void* ptr)
    {
        auto blockPtr = static_cast<MemoryBlock*>(ptr);
        blockPtr->free = true;

        // Merge adjacent free blocks
        auto it = memoryRegion.begin();
        while (it != memoryRegion.end())
        {
            if (it->free)
            {
                auto next = std::next(it);
                if (next != memoryRegion.end() && next->free)
                {
                    it->size += next->size;
                    memoryRegion.erase(next);
                }
            }
            it = std::next(it);
        }
    }

    void defragment()
    {
        std::sort(memoryRegion.begin(), memoryRegion.end(), [](const MemoryBlock& a, const MemoryBlock& b) {
            return a.free && !b.free;
        });
    }
};

// Unit tests using Google Test
class MemoryManagerTest : public ::testing::Test
{
protected:
    MemoryManager memoryManager;

    void SetUp() override
    {
        memoryManager.initialize(1024);
    }
};

TEST_F(MemoryManagerTest, AllocateAndDeallocate)
{
    void* ptr1 = memoryManager.allocate(128);
    ASSERT_NE(ptr1, nullptr);

    void* ptr2 = memoryManager.allocate(256);
    ASSERT_NE(ptr2, nullptr);

    memoryManager.deallocate(ptr1);
    memoryManager.deallocate(ptr2);
}

TEST_F(MemoryManagerTest, Defragment)
{
    void* ptr1 = memoryManager.allocate(128);
    void* ptr2 = memoryManager.allocate(256);
    memoryManager.deallocate(ptr1);
    memoryManager.deallocate(ptr2);

    memoryManager.defragment();
    ASSERT_EQ(memoryManager.allocate(384), ptr1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
