#include <vector>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int val) : value(val) {}

    void addChild(Node* pChild) {
        children.push_back(pChild);
    }
};