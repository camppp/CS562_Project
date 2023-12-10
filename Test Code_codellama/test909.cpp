// Visitor interface
class Visitor {
public:
    virtual void visit(const gencode_node& node) = 0;
    virtual void visit(const expand_node& node) = 0;
    virtual void visit(const add_node& node) = 0;
    virtual void visit(const load_node& node) = 0;
};

// Visitor classes
class GencodeVisitor : public Visitor {
public:
    void visit(const gencode_node& node) override {
        // Implement the gencode operation
    }
};

class ExpandVisitor : public Visitor {
public:
    void visit(const expand_node& node) override {
        // Implement the expand operation
    }
};

class AddVisitor : public Visitor {
public:
    void visit(const add_node& node) override {
        // Implement the add operation
    }
};

class LoadVisitor : public Visitor {
public:
    void visit(const load_node& node) override {
        // Implement the load operation
    }
};

// Traversal mechanism
void traverse(const expression_tree& tree, Visitor& visitor) {
    for (const auto& node : tree.nodes) {
        switch (node.type) {
            case gencode_node:
                visitor.visit(static_cast<const gencode_node&>(node));
                break;
            case expand_node:
                visitor.visit(static_cast<const expand_node&>(node));
                break;
            case add_node:
                visitor.visit(static_cast<const add_node&>(node));
                break;
            case load_node:
                visitor.visit(static_cast<const load_node&>(node));
                break;
        }
    }
}

// Example usage
expression_tree tree;
GencodeVisitor gencode_visitor;
ExpandVisitor expand_visitor;
AddVisitor add_visitor;
LoadVisitor load_visitor;

traverse(tree, gencode_visitor);
traverse(tree, expand_visitor);
traverse(tree, add_visitor);
traverse(tree, load_visitor);
