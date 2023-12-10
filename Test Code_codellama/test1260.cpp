#include <iostream>
#include <map>
#include <vector>

class ConcreteParams : public Params {
public:
    ConcreteParams() {}

    void SetMapAgentIdListFloat(const std::map<std::string, std::vector<float>>& map) {
        // Set the map of agent IDs to lists of floating-point values
        this->map = map;
    }

    int operator[](const std::string& name) {
        // Retrieve an integer value associated with a parameter name
        return this->map[name];
    }

    void AddChild(const std::string& name) {
        // Add a child parameter with a given name
        this->children.push_back(name);
    }

private:
    std::map<std::string, std::vector<float>> map;
    std::vector<std::string> children;
};
