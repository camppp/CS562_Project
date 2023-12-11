std::size_t CalculateTotalMemorySize(const Pomdog::MeshPart* meshParts, std::size_t count) {
    std::size_t totalSize = 0;
    for (std::size_t i = 0; i < count; ++i) {
        totalSize += sizeof(Pomdog::MeshPart);
    }
    return totalSize;
}
