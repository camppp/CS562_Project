c
#include <windows.h>
#include <psapi.h>

LPVOID FindNearestFreeMemoryBlock(LPVOID nearest)
{
    MEMORY_BASIC_INFORMATION mbi;
    SIZE_T size = 0;
    LPVOID freeBlock = NULL;

    // Initialize the MEMORY_BASIC_INFORMATION structure
    ZeroMemory(&mbi, sizeof(mbi));

    // Iterate through the process's memory space
    while (VirtualQuery(nearest, &mbi, sizeof(mbi)) != 0)
    {
        // Check if the memory block is free
        if (mbi.State == MEM_FREE)
        {
            // If the free memory block is closer to the input address than the previous free block, update the previous free block
            if (nearest - mbi.BaseAddress < size)
            {
                freeBlock = mbi.BaseAddress;
                size = nearest - mbi.BaseAddress;
            }
        }

        // Move to the next memory block
        nearest = (LPVOID)((ULONG_PTR)nearest + mbi.RegionSize);
    }

    // Return the address of the nearest free memory block
    return freeBlock;
}
