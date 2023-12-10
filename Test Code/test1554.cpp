#include <iostream>
#include <vector>
#include <string>

struct Node {
    std::string name;
    std::vector<Node> children;
};

class Directory {
public:
    Directory(const std::string& name) : name(name) {}

    std::string find_resource_file(const std::string& file_name) const {
        return find_resource_file_helper(root, file_name, "");
    }

    void add_child(const std::string& parent_path, const std::string& child_name) {
        Node* parent = find_node(root, parent_path);
        if (parent != nullptr) {
            parent->children.push_back(Node{child_name, {}});
        }
    }

private:
    Node root;
    std::string name;

    std::string find_resource_file_helper(const Node& node, const std::string& file_name, const std::string& path) const {
        if (node.name == file_name) {
            return path + "/" + node.name;
        }
        for (const auto& child : node.children) {
            std::string result = find_resource_file_helper(child, file_name, path + "/" + node.name);
            if (!result.empty()) {
                return result;
            }
        }
        return "";
    }

    Node* find_node(Node& node, const std::string& path) {
        if (path.empty()) {
            return &node;
        }
        size_t pos = path.find('/');
        std::string current_name = path.substr(0, pos);
        for (auto& child : node.children) {
            if (child.name == current_name) {
                return find_node(child, pos == std::string::npos ? "" : path.substr(pos + 1));
            }
        }
        return nullptr;
    }
};

int main() {
    Directory iom("resources");
    iom.add_child("substances", "Oxygen5.xml");
    std::cout << iom.find_resource_file("Oxygen5.xml") << std::endl;  // Output: /substances/Oxygen5.xml
    std::cout << iom.find_resource_file("Nonexistent.xml") << std::endl;  // Output: 
    return 0;
}
