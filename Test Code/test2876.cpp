#include <iostream>
#include <unordered_map>

class Tree {
    // Define the Tree class as per the requirements
};

class TreeManager {
private:
    std::unordered_map<int, Tree*> trees;

public:
    void addTree(int buf) {
        // Create a new tree and add it to the collection
        trees[buf] = new Tree();
    }

    void removeTree(int buf) {
        // Remove the tree with the given buffer index
        auto it = trees.find(buf);
        if (it != trees.end()) {
            delete it->second;
            trees.erase(it);
        }
    }

    Tree* getTree(int buf) {
        // Return the tree with the given buffer index
        auto it = trees.find(buf);
        if (it != trees.end()) {
            return it->second;
        }
        return nullptr;  // Tree not found
    }

    void onDetach(int buf) {
        // Handle the event when a tree with buffer index buf is detached
        auto it = trees.find(buf);
        if (it != trees.end()) {
            delete it->second;
            trees.erase(it);
            std::cout << "\tAfter remove " << buf << ", trees:";
            for (auto& pair : trees) {
                std::cout << pair.first << ",";
            }
            std::cout << std::endl;
        }
    }

    ~TreeManager() {
        // Clean up all remaining trees in the destructor
        for (auto& pair : trees) {
            delete pair.second;
        }
        trees.clear();
    }
};

int main() {
    TreeManager manager;
    manager.addTree(1);
    manager.addTree(2);
    manager.addTree(3);

    manager.removeTree(2);

    Tree* tree1 = manager.getTree(1);
    if (tree1) {
        // Perform operations on tree1
    }

    manager.onDetach(1);

    return 0;
}
