#include <iostream>
#include <vector>

class SceneNode {
private:
    std::vector<SceneNode*> children;
public:
    void addChild(SceneNode* child) {
        children.push_back(child);
    }

    void removeChild(SceneNode* child) {
        auto it = std::find(children.begin(), children.end(), child);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    void traverse() {
        // Perform an operation on the current node
        // For example, printing the node's information
        std::cout << "Performing operation on current node" << std::endl;

        // Traverse each child node recursively
        for (auto child : children) {
            child->traverse();
        }
    }
};

int main() {
    // Create the root node of the scene graph
    SceneNode* scene = new SceneNode();

    // Create a child node
    SceneNode* layer = new SceneNode();

    // Add the child node to the scene graph
    scene->addChild(layer);

    // Traverse the scene graph and perform an operation on each node
    scene->traverse();

    // Clean up memory by deleting the nodes
    delete layer;
    delete scene;

    return 0;
}
