std::size_t largestSetSize(const std::vector<std::pair<value_type, value_type>>& mergeOperations) {
    std::size_t maxSize = 0;
    for (const auto& mergeOp : mergeOperations) {
        merge(mergeOp.first, mergeOp.second);
        maxSize = std::max(maxSize, numberOfElements());
    }
    return maxSize;
}
