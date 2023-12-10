int findElementInReversedChunks(const std::list<std::vector<int>>& chunks, int element) {
    auto it = std::find_if(chunks.rbegin(), chunks.rend(), [element](const std::vector<int>& chunk) {
        return std::find(chunk.begin(), chunk.end(), element) != chunk.end();
    });

    if (it != chunks.rend()) {
        return std::distance(it, chunks.rbegin());
    } else {
        return -1;
    }
}
