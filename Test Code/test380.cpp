#include <cstdint>
#include <unordered_map>

class MemoryManager {
private:
    std::unordered_map<uint64_t, uint64_t> memoryRegions;

public:
    void AddMemoryRegion(uint64_t base, uint64_t size) {
        memoryRegions[base] = size;
    }

    void RemoveMemoryRegion(uint64_t base) {
        memoryRegions.erase(base);
    }

    bool IsRangeAvailable(uint64_t base, uint64_t size) {
        for (const auto& region : memoryRegions) {
            if (base >= region.first && base + size <= region.first + region.second) {
                return false;  // Range overlaps with an existing region
            }
            if (base <= region.first && base + size > region.first) {
                return false;  // Range overlaps with an existing region
            }
        }
        return true;  // Range does not overlap with any existing region
    }
};

int main() {
    MemoryManager memoryManager;

    // Add memory regions
    memoryManager.AddMemoryRegion(0x1000, 0x2000);
    memoryManager.AddMemoryRegion(0x5000, 0x1000);

    // Check range availability
    bool isAvailable1 = memoryManager.IsRangeAvailable(0x2000, 0x1000);  // Should return true
    bool isAvailable2 = memoryManager.IsRangeAvailable(0x3000, 0x1000);  // Should return false
    bool isAvailable3 = memoryManager.IsRangeAvailable(0x4000, 0x1000);  // Should return true

    return 0;
}
