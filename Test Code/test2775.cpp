#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    Node(std::vector<Node*> children, std::pair<int, int> position) : m_children(children), position(position) {}

    void move(std::pair<int, int> newPosition) {
        // Calculate the offset by which the node is being moved
        int xOffset = newPosition.first - position.first;
        int yOffset = newPosition.second - position.second;

        // Move the node to the new position
        position = newPosition;

        // Move all child nodes by the same offset to maintain their relative positions
        for (auto& child : m_children) {
            child->move(std::make_pair(child->position.first + xOffset, child->position.second + yOffset));
        }
    }

private:
    std::pair<int, int> position;
    std::vector<Node*> m_children;
};

int main() {
    // Create a hierarchy of nodes
    Node* child1 = new Node({}, std::make_pair(1, 1));
    Node* child2 = new Node({}, std::make_pair(2, 2));
    Node* parent = new Node({child1, child2}, std::make_pair(0, 0));

    // Move the parent node and observe the movement of child nodes
    parent->move(std::make_pair(3, 3));

    // Clean up memory by deleting the nodes
    delete child1;
    delete child2;
    delete parent;

    return 0;
}
