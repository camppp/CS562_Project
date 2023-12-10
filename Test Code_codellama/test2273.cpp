Bounds2i flipBounds(const Bounds2i& b2) {
    // Get the minimum and maximum coordinates of the original bounding box
    std::pair<int, int> minCoords = b2.min();
    std::pair<int, int> maxCoords = b2.max();

    // Swap the x and y coordinates of the minimum and maximum points
    std::pair<int, int> flippedMinCoords(maxCoords.first, minCoords.second);
    std::pair<int, int> flippedMaxCoords(minCoords.first, maxCoords.second);

    // Create a new Bounds2i object with the swapped coordinates
    return Bounds2i(flippedMinCoords, flippedMaxCoords);
}
