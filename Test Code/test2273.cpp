Bounds2i flipBounds(const Bounds2i& b2) {
    std::pair<int, int> minCoords = b2.min();
    std::pair<int, int> maxCoords = b2.max();
    Bounds2i b2flipped(std::min(minCoords.second, maxCoords.second), std::min(minCoords.first, maxCoords.first),
                      std::max(minCoords.second, maxCoords.second), std::max(minCoords.first, maxCoords.first));
    return b2flipped;
}
