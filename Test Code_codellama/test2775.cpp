#include <vector>
#include <iostream>

class Node {
public:
    Node(const std::vector<Node*>& children) : m_children(children) {}

    void move(const std::vector<double>& position) {
        // Move the node to the new position
        m_position = position;

        // Move all child nodes to maintain their relative positions
        for (auto child : m_children) {
            child->move(position + child->getPosition());
        }
    }

    const std::vector<double>& getPosition() const {
        return m_position;
    }

private:
    std::vector<double> m_position;
    std::vector<Node*> m_children;
};
