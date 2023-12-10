#include <cstdint>

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
