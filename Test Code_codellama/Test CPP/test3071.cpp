class CustomOperation {
  public:
    int execute(Scope* scope, ActionNode* action) {
      // Retrieve the two operands of the custom type
      HighInstance* operand1 = action->getOperand1();
      HighInstance* operand2 = action->getOperand2();

      // Perform the specified operation based on the action node
      switch (action->getActionType()) {
        case ActionType::COMPARE:
          // Perform comparison operation
          if (operand1->getValue() < operand2->getValue()) {
            return -1;
          } else if (operand2->getValue() < operand1->getValue()) {
            return 1;
          } else {
            return 0;
          }
        case ActionType::ADD:
          // Perform addition operation
          return operand1->getValue() + operand2->getValue();
        default:
          // Unsupported action type
          return 0;
      }
    }
};
