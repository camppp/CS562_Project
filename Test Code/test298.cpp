#include <iostream>
#include <string>
#include <vector>

class TreeNode {
private:
    std::string name;
    std::vector<TreeNode*> children;

public:
    TreeNode(const std::string& node_name) : name(node_name) {}

    void add_child(TreeNode* child_node) {
        children.push_back(child_node);
    }

    std::vector<std::string> get_children() const {
        std::vector<std::string> child_names;
        for (const auto& child : children) {
            child_names.push_back(child->name);
        }
        return child_names;
    }

    void get_descendants_helper(std::vector<std::string>& descendants) const {
        for (const auto& child : children) {
            descendants.push_back(child->name);
            child->get_descendants_helper(descendants);
        }
    }

    std::vector<std::string> get_descendants() const {
        std::vector<std::string> descendants;
        get_descendants_helper(descendants);
        return descendants;
    }
};

int main() {
    TreeNode root("Root");
    TreeNode child1("Child1");
    TreeNode child2("Child2");
    TreeNode grandchild("Grandchild");

    root.add_child(&child1);
    root.add_child(&child2);
    child2.add_child(&grandchild);

    std::cout << "Children of Root: ";
    for (const auto& child : root.get_children()) {
        std::cout << child << " ";
    }
    std::cout << std::endl;

    std::cout << "Descendants of Root: ";
    for (const auto& descendant : root.get_descendants()) {
        std::cout << descendant << " ";
    }
    std::cout << std::endl;

    return 0;
}
