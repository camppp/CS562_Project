void printExpression(std::ostream& os, bool post, const Operand& expr, const Operator& op) {
  if (post) {
    os << expr << op;
  } else {
    os << op << expr;
  }
}
