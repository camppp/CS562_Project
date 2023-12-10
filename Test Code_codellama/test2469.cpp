#include "iceoryx_posh/internal/mepoo/memory_manager.hpp"
#include "iceoryx_posh/mepoo/mepoo_config.hpp"
#include "iceoryx_utils/internal/posix_wrapper/shared_memory_object/allocator.hpp"
#include "test.hpp"

using namespace ::testing;

class MemoryManager_test : public Test
{
  public:
    void SetUp()
    {
        // Your initialization code here
    }

    void TearDown()
    {
        // Your cleanup code here
    }

    void test_allocate_and_deallocate()
    {
        // Allocate a memory block of size 100
        auto block = memoryManager.allocate(100);
        ASSERT_NE(block, nullptr);

        // Deallocate the memory block
        memoryManager.deallocate(block);

        // Allocate a memory block of size 200
        block = memoryManager.allocate(200);
        ASSERT_NE(block, nullptr);

        // Deallocate the memory block
        memoryManager.deallocate(block);
    }

    void test_defragment()
    {
        // Allocate a memory block of size 100
        auto block1 = memoryManager.allocate(100);
        ASSERT_NE(block1, nullptr);

        // Allocate a memory block of size 200
        auto block2 = memoryManager.allocate(200);
        ASSERT_NE(block2, nullptr);

        // Deallocate the memory block of size 100
        memoryManager.deallocate(block1);

        // Defragment the memory region
        memoryManager.defragment();

        // Allocate a memory block of size 100
        block1 = memoryManager.allocate(100);
        ASSERT_NE(block1, nullptr);

        // Allocate a memory block of size 200
        block2 = memoryManager.allocate(200);
        ASSERT_NE(block2, nullptr);

        // Deallocate the memory block of size 200
        memoryManager.deallocate(block2);

        // Defragment the memory region
        memoryManager.defragment();

        // Allocate a memory block of size 100
        block1 = memoryManager.allocate(100);
        ASSERT_NE(block1, nullptr);

        // Allocate a memory block of size 200
        block2 = memoryManager.allocate(200);
        ASSERT_NE(block2, nullptr);
    }

    void test_edge_cases()
    {
        // Allocate a memory block of size 0
        auto block = memoryManager.allocate(0);
        ASSERT_EQ(block, nullptr);

        // Deallocate a nullptr
        memoryManager.deallocate(nullptr);

        // Defragment a nullptr
        memoryManager.defragment(nullptr);
    }

    void test_error_conditions()
    {
        // Allocate a memory block of size 100
        auto block = memoryManager.allocate(100);
        ASSERT_NE(block, nullptr);

        // Deallocate the memory block
        memoryManager.deallocate(block);

        // Try to deallocate the memory block again
        memoryManager.deallocate(block);

        // Try to defragment the memory region
        memoryManager.defragment();
    }

  private:
    MemoryManager memoryManager;
};
