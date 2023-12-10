LPVOID FindNearestFreeMemoryBlock(LPVOID nearest) {
    MEMORY_BASIC_INFORMATION mbi = { 0 };
    LPVOID nearestFreeBlock = NULL;

    for (SIZE_T addr = (SIZE_T)nearest; addr > (SIZE_T)nearest - 0x80000000; addr = (SIZE_T)mbi.BaseAddress - 1) {
        if (!VirtualQuery((LPCVOID)addr, &mbi, sizeof(mbi)))
            break;

        if (mbi.State == MEM_FREE) {
            nearestFreeBlock = mbi.BaseAddress;
            break;
        }
    }

    return nearestFreeBlock;
}
