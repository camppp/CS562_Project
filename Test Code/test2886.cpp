#include <iostream>
#include <cstdint>

// Define the BinaryBuffer class for demonstration purposes
class BinaryBuffer {
public:
    uint16_t PopUint16() {
        // Simulated function to pop a 16-bit unsigned integer from the buffer
        return 0; // Replace with actual implementation
    }

    uint64_t PopUint64() {
        // Simulated function to pop a 64-bit unsigned integer from the buffer
        return 0; // Replace with actual implementation
    }

    uint32_t PopUint32() {
        // Simulated function to pop a 32-bit unsigned integer from the buffer
        return 0; // Replace with actual implementation
    }
};

struct StorageInfo {
    uint16_t filesystemType;
    uint16_t accessCapability;
    uint64_t maxCapacity;
    uint64_t freeSpaceInMB;
    uint32_t freeSpaceInObjects;
};

StorageInfo parseStorageInfo(const BinaryBuffer& v) {
    StorageInfo info;
    info.filesystemType = v.PopUint16();
    info.accessCapability = v.PopUint16();
    info.maxCapacity = v.PopUint64() >> 20; // Round down to MB
    info.freeSpaceInMB = v.PopUint64() >> 20; // Round down to MB
    info.freeSpaceInObjects = v.PopUint32();
    return info;
}

int main() {
    // Example usage
    BinaryBuffer buffer; // Initialize with actual data
    StorageInfo storageInfo = parseStorageInfo(buffer);
    std::cout << "File System Type: " << storageInfo.filesystemType << std::endl;
    std::cout << "Access Capability: " << storageInfo.accessCapability << std::endl;
    std::cout << "Max Capacity (MB): " << storageInfo.maxCapacity << std::endl;
    std::cout << "Free Space (MB): " << storageInfo.freeSpaceInMB << std::endl;
    std::cout << "Free Space (Objects): " << storageInfo.freeSpaceInObjects << std::endl;
    return 0;
}
