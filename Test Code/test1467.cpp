#include <vector>
#include <algorithm>

class Node {
public:
    Node* parent;
    std::vector<Node*> children;

    void setParent(Node *theParent) {
        parent = theParent;
        parent->children.push_back(this);
    }
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int maxHeight = 0;
    for (Node* child : node->children) {
        maxHeight = std::max(maxHeight, getHeight(child));
    }
    return 1 + maxHeight;
}

int findMaxHeight(std::vector<Node>& nodes) {
    Node* root = nullptr;
    for (Node& node : nodes) {
        if (node.parent == nullptr) {
            root = &node;
            break;
        }
    }
    return getHeight(root);
}
