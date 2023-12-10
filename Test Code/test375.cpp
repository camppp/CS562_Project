#include <iostream>
#include <unordered_map>
#include <vector>

class Tree {
private:
    std::unordered_map<std::string, std::vector<std::string>> _children;
    std::string _full_path;

public:
    std::string GetFullPath(const std::string &child) const {
        if (_full_path.empty()) {
            return child;
        } else {
            return _full_path + "." + child;
        }
    }

    void Clear() {
        _children.clear();
        _full_path.clear();
    }

    void AddChild(const std::string &parent, const std::string &child) {
        if (_children.find(parent) != _children.end()) {
            _children[parent].push_back(child);
        }
    }

    void PrintTreeHelper(const std::string &node, int depth) const {
        if (_children.find(node) != _children.end()) {
            for (const auto &child : _children.at(node)) {
                for (int i = 0; i < depth; ++i) {
                    std::cout << "  ";
                }
                std::cout << "- " << child << std::endl;
                PrintTreeHelper(child, depth + 1);
            }
        }
    }

    void PrintTree() const {
        if (_children.empty()) {
            std::cout << "Tree is empty." << std::endl;
        } else {
            std::cout << "Tree structure:" << std::endl;
            PrintTreeHelper("", 0);
        }
    }
};

int main() {
    Tree tree;
    tree.AddChild("", "root");
    tree.AddChild("root", "child1");
    tree.AddChild("root", "child2");
    tree.AddChild("child1", "grandchild1");
    tree.AddChild("child1", "grandchild2");
    tree.AddChild("child2", "grandchild3");
    tree.PrintTree();
    return 0;
}
