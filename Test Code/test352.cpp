#include <iostream>

// Forward declaration of classes
class BM188X;
class AveragePool;

// Forward declaration of visitor classes
class ComputeVisitor {
public:
    virtual void visit(const BM188X& bm188x) = 0;
    virtual void visit(const AveragePool& averagePool) = 0;
};

class BM188xVisitor : public ComputeVisitor {
public:
    void visit(const BM188X& bm188x) override {
        // Specific operations for visiting BM188X
        std::cout << "Visiting BM188X" << std::endl;
    }

    void visit(const AveragePool& averagePool) override {
        // Specific operations for visiting AveragePool
        std::cout << "Visiting AveragePool" << std::endl;
    }
};

class BM188X {
public:
    void accept(ComputeVisitor& pV) const {
        pV.visit(*this);
    }
};

class AveragePool {
public:
    void accept(ComputeVisitor& pV) const {
        pV.visit(*this);
    }
};

int main() {
    BM188xVisitor visitor;

    BM188X bm188x;
    AveragePool averagePool;

    bm188x.accept(visitor);  // Output: Visiting BM188X
    averagePool.accept(visitor);  // Output: Visiting AveragePool

    return 0;
}
