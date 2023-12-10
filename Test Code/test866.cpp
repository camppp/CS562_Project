#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class GraphNode {
private:
    std::string species;
    std::vector<GraphNode*> neighbors;

public:
    GraphNode(const std::string& species) : species(species) {}

    void AddNeighbor(GraphNode* neighbor) {
        neighbors.push_back(neighbor);
    }

    const std::string& GetSpecies() const {
        return species;
    }

    std::vector<std::string> GetNeighbors() const {
        std::vector<std::string> neighborSpecies;
        for (const auto& neighbor : neighbors) {
            neighborSpecies.push_back(neighbor->GetSpecies());
        }
        return neighborSpecies;
    }
};

int main() {
    // Create species nodes
    GraphNode s1("L1");
    GraphNode s2("L2");
    GraphNode s3("L3");
    GraphNode s4("L4");

    // Connect species nodes
    s1.AddNeighbor(&s2);
    s1.AddNeighbor(&s3);
    s1.AddNeighbor(&s4);

    // Verify
    std::vector<std::string> vals = {"L2", "L3", "L4"};
    auto neighbors = s1.GetNeighbors();
    int i = 0;
    for (const auto& neighbor : neighbors) {
        assert(vals[i] == neighbor);
        i++;
    }

    std::cout << "GetNeighbors test passed!" << std::endl;

    return 0;
}
