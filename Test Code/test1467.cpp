class Node {
public:
    Node* parent;
    vector<Node*> children;

    void setParent(Node* parent) {
        this->parent = parent;
        if (parent) {
            parent->children.push_back(this);
        }
    }

    int findMaxHeight(vector<Node*> nodes) {
        int maxHeight = 0;
        for (Node* node : nodes) {
            if (node->parent) {
                maxHeight = max(maxHeight, node->parent->findMaxHeight(nodes) + 1);
            }
        }
        return maxHeight;
    }
};
