void logAllocatedMemoryInMB() {
    // Calculate the total allocated memory for importon maps and buffers
    size_t totalAllocatedMemory = m_importonMapSize * 2 * 4 + mapDataSize * 8 * 4 + 4 * 4;

    // Log the allocated memory in megabytes (MB)
    std::cout << "Total allocated memory for importon maps and buffers: " << totalAllocatedMemory / (1024 * 1024) << " MB" << std::endl;
}
