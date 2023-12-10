#include <cstddef>

namespace Pomdog {

class MeshPart {
public:
    std::uint16_t VertexCount;
    std::uint16_t VertexOffset;
    std::uint16_t PrimitiveCount;
    std::uint16_t StartIndex;
};

} // namespace Pomdog

std::size_t CalculateTotalMemorySize(const Pomdog::MeshPart* meshParts, std::size_t count) {
    constexpr std::size_t instanceSize = sizeof(Pomdog::MeshPart);
    constexpr std::size_t alignment = 2; // bytes

    std::size_t totalSize = instanceSize * count;

    // Check if padding is required for alignment
    if (totalSize % alignment != 0) {
        totalSize += alignment - (totalSize % alignment);
    }

    return totalSize;
}
