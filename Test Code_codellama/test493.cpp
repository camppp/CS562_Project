#include <AzCore/Memory/Memory.h>

class LegacyTimeDemoRecorderModuleAllocator
{
public:
    static void* Allocate(size_t size, size_t alignment)
    {
        // Implement memory allocation logic here
        // ...
        return nullptr;
    }

    static void Deallocate(void* ptr)
    {
        // Implement memory deallocation logic here
        // ...
    }
};

AZ_CLASS_ALLOCATOR(LegacyTimeDemoRecorderModule, LegacyTimeDemoRecorderModuleAllocator);
