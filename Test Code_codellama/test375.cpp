#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Tree {
public:
    // Constructor
    Tree() {}

    // Destructor
    ~Tree() {}

    // Add a child node to the specified parent node
    void AddChild(const std::string &parent, const std::string &child) {
        // Check if the parent node exists
        if (nodes_.find(parent) == nodes_.end()) {
            return;
        }

        // Add the child node to the parent node
        nodes_[parent].push_back(child);
    }

    // Clear the tree by removing all nodes and resetting the tree to an empty state
    void Clear() {
        nodes_.clear();
    }

    // Get the full path from the root to the specified child node
    std::string GetFullPath(const std::string &child) const {
        // Check if the child node exists
        if (nodes_.find(child) == nodes_.end()) {
            return child;
        }

        // Get the parent node of the child node
        std::string parent = nodes_.at(child).front();

        // Recursively get the full path from the root to the parent node
        return GetFullPath(parent) + "." + child;
    }

    // Print the hierarchical structure of the tree
    void PrintTree() const {
        // Print the root node
        std::cout << "Root: " << nodes_.begin()->first << std::endl;

        // Recursively print the child nodes of the root node
        PrintTree(nodes_.begin()->first);
    }

private:
    // Map of nodes in the tree, where the key is the node name and the value is a vector of child node names
    std::unordered_map<std::string, std::vector<std::string>> nodes_;

    // Recursive function to print the child nodes of a given node
    void PrintTree(const std::string &node) const {
        // Check if the node has child nodes
        if (nodes_.find(node) == nodes_.end()) {
            return;
        }

        // Print the child nodes of the current node
        for (const auto &child : nodes_.at(node)) {
            std::cout << "  " << child << std::endl;
            PrintTree(child);
        }
    }
};
