bool IsRangeAvailable(uint64_t base, uint64_t size) {
    // Iterate over the existing memory regions
    for (auto& region : regions) {
        // Check if the current region overlaps with the specified range
        if (region.base <= base && base + size <= region.base + region.size) {
            // If the current region overlaps with the specified range, return false
            return false;
        }
    }

    // If no overlapping regions were found, return true
    return true;
}
