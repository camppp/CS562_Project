class PlacementManager {
private:
    std::vector<Placement> placements;
    int total_min_replicas;

public:
    PlacementManager() : total_min_replicas(0) {}

    void addPlacement(const std::string& cloud, const std::string& region, const std::string& zone, int min_replicas) {
        placements.push_back({cloud, region, zone, min_replicas});
        total_min_replicas += min_replicas;
    }

    int getTotalMinReplicas() const {
        return total_min_replicas;
    }
};
