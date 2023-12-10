#include <memory>

class Expr {
private:
  std::unique_ptr<Expr> value;

public:
  Expr() : value(nullptr) {}  // Default constructor
  ~Expr() = default;  // Destructor

  Expr* getValue() { return value.get(); }
  const Expr* getValue() const { return value.get(); }
  void setValue(std::unique_ptr<Expr>&& expr) { value = std::move(expr); }

  // Evaluate the expression tree
  int evaluate(const Expr* root) {
    if (root == nullptr) {
      // Handle empty tree or leaf node
      return 0;
    } else if (root->getValue() == nullptr) {
      // Leaf node representing a numeric value
      return root->getValue()->evaluate(root->getValue());
    } else {
      // Internal node representing an operator
      const Expr* left = root->getValue();
      const Expr* right = root->getValue()->getValue();
      switch (root->getValue()->getType()) {
        case OperatorType::ADD:
          return evaluate(left) + evaluate(right);
        case OperatorType::SUBTRACT:
          return evaluate(left) - evaluate(right);
        // Handle other operator types
      }
    }
  }
};
