#include <iostream>

// Forward declarations of node classes
class gencode_node;
class expand_node;
class add_node;
class load_node;

// Visitor interface
class NodeVisitor {
public:
    virtual void visit(gencode_node& n) = 0;
    virtual void visit(expand_node& n)  = 0;
    virtual void visit(add_node& n)     = 0;
    virtual void visit(load_node& n)    = 0;
};

// Node classes
class Node {
public:
    virtual void accept(NodeVisitor& visitor) = 0;
};

class gencode_node : public Node {
public:
    void accept(NodeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

class expand_node : public Node {
public:
    void accept(NodeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

class add_node : public Node {
public:
    void accept(NodeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

class load_node : public Node {
public:
    void accept(NodeVisitor& visitor) override {
        visitor.visit(*this);
    }
};

// Concrete visitor classes
class ConcreteVisitor : public NodeVisitor {
public:
    void visit(gencode_node& n) override {
        std::cout << "Visiting gencode_node" << std::endl;
    }

    void visit(expand_node& n) override {
        std::cout << "Visiting expand_node" << std::endl;
    }

    void visit(add_node& n) override {
        std::cout << "Visiting add_node" << std::endl;
    }

    void visit(load_node& n) override {
        std::cout << "Visiting load_node" << std::endl;
    }
};

// Traversal mechanism
void traverse(Node& node, NodeVisitor& visitor) {
    node.accept(visitor);
}

int main() {
    ConcreteVisitor visitor;

    gencode_node gnode;
    expand_node enode;
    add_node anode;
    load_node lnode;

    traverse(gnode, visitor);
    traverse(enode, visitor);
    traverse(anode, visitor);
    traverse(lnode, visitor);

    return 0;
}
