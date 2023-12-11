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
