#include <iostream>

// Define a custom type for the operands
class CustomInstance {
public:
    virtual int value() const = 0;
};

// Define the CustomOperation class
class CustomOperation {
public:
    virtual CustomInstance* execute(scope::Scope& scope, type::Node& action_node) = 0;
};

// Define a class for comparison operation
class CustomCmp : public CustomOperation {
public:
    CustomInstance* execute(scope::Scope& scope, type::Node& action_node) override {
        auto arg1 = _operand<CustomInstance>(scope, action_node, 0);
        auto arg2 = _operand<CustomInstance>(scope, action_node, 1);
        int result = arg1->value() < arg2->value() ? -1 : arg2->value() < arg1->value() ? 1 : 0;
        return new IntInstance(result);
    }
};

// Define a class for addition operation
class CustomPlus : public CustomOperation {
public:
    CustomInstance* execute(scope::Scope& scope, type::Node& action_node) override {
        auto arg1 = _operand<CustomInstance>(scope, action_node, 0);
        auto arg2 = _operand<CustomInstance>(scope, action_node, 1);
        int result = arg1->value() + arg2->value();
        return new IntInstance(result);
    }
};

// Example usage
int main() {
    // Create instances of CustomInstance with specific values
    CustomInstance* instance1 = new IntInstance(5);
    CustomInstance* instance2 = new IntInstance(3);

    // Perform comparison operation
    CustomOperation* cmpOperation = new CustomCmp();
    CustomInstance* cmpResult = cmpOperation->execute(scope, action_node);
    std::cout << "Comparison result: " << cmpResult->value() << std::endl;

    // Perform addition operation
    CustomOperation* plusOperation = new CustomPlus();
    CustomInstance* plusResult = plusOperation->execute(scope, action_node);
    std::cout << "Addition result: " << plusResult->value() << std::endl;

    return 0;
}
