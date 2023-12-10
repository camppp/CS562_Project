#include <iostream>

class Operand {
public:
  Operand(const std::string& value) : value_(value) {}
  friend std::ostream& operator<<(std::ostream& os, const Operand& operand) {
    os << operand.value_;
    return os;
  }

private:
  std::string value_;
};

class Operator {
public:
  Operator(const std::string& symbol) : symbol_(symbol) {}
  friend std::ostream& operator<<(std::ostream& os, const Operator& op) {
    os << op.symbol_;
    return os;
  }

private:
  std::string symbol_;
};

void printExpression(std::ostream& os, bool post_, const Operand& expr_, const Operator& op_) {
  if (post_)
    os << expr_ << " " << op_;
  else
    os << op_ << " " << expr_;
}

int main() {
  Operand expr("5");
  Operator op("+");

  std::cout << "Postfix format: ";
  printExpression(std::cout, true, expr, op);
  std::cout << std::endl;

  std::cout << "Prefix format: ";
  printExpression(std::cout, false, expr, op);
  std::cout << std::endl;

  return 0;
}
