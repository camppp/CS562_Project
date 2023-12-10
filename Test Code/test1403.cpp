#include <iostream>
#include <vector>
#include <memory>

// Token class representing numerical values or operators
class Token {
public:
    using Ptr = std::shared_ptr<Token>;
    virtual ~Token() = default;
};

// Numerical token class derived from Token
class NumToken : public Token {
public:
    double value;
    NumToken(double val) : value(val) {}
};

// Function to convert a token to a numerical value
double token_to_num(Token::Ptr tok) {
    return static_cast<NumToken*>(tok.get())->value;
}

// Function to perform addition operation on input tokens
Token::Ptr op_add(const std::vector<Token::Ptr> &args) {
    double sum = 0;
    for (const auto &tok : args) {
        sum += token_to_num(tok);
    }
    return std::make_shared<NumToken>(sum);
}

// Function to perform subtraction operation on input tokens
Token::Ptr op_sub(const std::vector<Token::Ptr> &args) {
    double result = token_to_num(args[0]);
    for (size_t i = 1; i < args.size(); ++i) {
        result -= token_to_num(args[i]);
    }
    return std::make_shared<NumToken>(result);
}

// Function to evaluate the expression and return the final result
double evaluate_expression(const std::vector<Token::Ptr> &tokens) {
    // Logic to process the tokens and apply operations in correct order
    // Example: handle operator precedence, parentheses, etc.
    // For simplicity, assume correct input expression format for this problem

    // Example usage:
    // Token::Ptr result = op_add({std::make_shared<NumToken>(2), std::make_shared<NumToken>(3)});
    // double final_result = token_to_num(result);
    // std::cout << "Final result: " << final_result << std::endl;

    // Return the final result of the expression evaluation
    return token_to_num(op_add(tokens));
}

int main() {
    // Example usage of the evaluate_expression function
    std::vector<Token::Ptr> tokens = {
        std::make_shared<NumToken>(5),
        std::make_shared<NumToken>(3),
        std::make_shared<NumToken>(2),
        std::make_shared<NumToken>(1)
    };
    double result = evaluate_expression(tokens);
    std::cout << "Final result: " << result << std::endl;

    return 0;
}
