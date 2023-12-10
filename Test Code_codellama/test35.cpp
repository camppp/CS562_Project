ASTNode parseSelectionStatement(const std::vector<Token>& tokens) {
  // Create a new If node
  ASTNode ifNode = ASTNode(If);

  // Parse the expression within the selection statement
  ifNode.setExpression(expression(tokens));

  // Return the If node
  return ifNode;
}
