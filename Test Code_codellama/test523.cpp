#include <cstddef>

template <typename T>
size_t calculateStructureSize() {
    size_t size = 0;
    size_t alignment = 0;
    for (auto& member : T::members) {
        size += member.size;
        alignment = std::max(alignment, member.alignment);
    }
    size = (size + alignment - 1) / alignment * alignment;
    return size;
}
