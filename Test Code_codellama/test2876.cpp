#include <unordered_map>
#include <vector>

class TreeManager {
public:
    void addTree(int buf) {
        trees[buf] = Tree(buf);
    }

    void removeTree(int buf) {
        trees.erase(buf);
    }

    Tree& getTree(int buf) {
        return trees[buf];
    }

    void onDetach(int buf) {
        // Handle the event when a tree with buffer index buf is detached
    }

private:
    std::unordered_map<int, Tree> trees;
};

class Tree {
public:
    Tree(int buf) : buf(buf) {}

    int getBufferIndex() const {
        return buf;
    }

private:
    int buf;
};
