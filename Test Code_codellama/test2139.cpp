uint64_t LeafIndex::Calculate(uint64_t position) {
    // Calculate the leaf index by counting the number of leaf nodes
    // before the given position.
    uint64_t leafIndex = 0;
    for (uint64_t i = 0; i < position; i++) {
        if (isLeaf(i)) {
            leafIndex++;
        }
    }
    return leafIndex;
}
