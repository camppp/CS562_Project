const std::vector<std::string>& GetNeighbors() const {
    std::vector<std::string> neighbors;
    for (const auto& neighbor : neighbors) {
        neighbors.push_back(neighbor->GetSpecies());
    }
    return neighbors;
}
