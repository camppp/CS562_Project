#include <iostream>
#include <string>
#include <vector>

// Define the AST node structure
struct ast_node {
    std::string type;
    std::string value;
    std::vector<ast_node*> children;
};

// Define the parse_string function
ast_node* parse_string(const std::string& code) {
    // Tokenize the code
    std::vector<std::string> tokens = tokenize(code);

    // Create the AST
    ast_node* root = new ast_node();
    root->type = "BINARY_NODE";
    root->value = "ADD";

    // Parse the tokens
    for (int i = 0; i < tokens.size(); i++) {
        std::string token = tokens[i];
        if (token == "(") {
            // Create a new node for the left child
            ast_node* left = new ast_node();
            left->type = "BINARY_NODE";
            left->value = "MULTIPLY";

            // Add the left child to the root node
            root->children.push_back(left);

            // Parse the left child
            parse_string(tokens, i + 1, left);
        } else if (token == ")") {
            // Create a new node for the right child
            ast_node* right = new ast_node();
            right->type = "BINARY_NODE";
            right->value = "DIVIDE";

            // Add the right child to the root node
            root->children.push_back(right);

            // Parse the right child
            parse_string(tokens, i + 1, right);
        } else {
            // Create a new node for the value
            ast_node* value = new ast_node();
            value->type = "VALUE_NODE";
            value->value = token;

            // Add the value to the root node
            root->children.push_back(value);
        }
    }

    return root;
}

// Tokenize the code
std::vector<std::string> tokenize(const std::string& code) {
    std::vector<std::string> tokens;
    std::string token;
    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        if (c == '(' || c == ')' || c == '*' || c == '/') {
            tokens.push_back(token);
            token = "";
        }
        token += c;
    }
    tokens.push_back(token);
    return tokens;
}

int main() {
    // Test the parser
    std::string test_code = "((3 * 4) / 5)";
    ast_node* block = parse_string(test_code);
    ast_node* node = block->children[0];
    assert(node->type == "BINARY_NODE");
    assert(node->value == "ADD");
    assert(node->children[0]->type == "BINARY_NODE");
    assert(node->children[0]->value == "MULTIPLY");
    assert(node->children[0]->children[0]->type == "VALUE_NODE");
    assert(node->children[0]->children[0]->value == "3");
    assert(node->children[0]->children[1]->type == "VALUE_NODE");
    assert(node->children[0]->children[1]->value == "4");
    assert(node->children[1]->type == "BINARY_NODE");
    assert(node->children[1]->value == "DIVIDE");
    assert(node->children[1]->children[0]->type == "VALUE_NODE");
    assert(node->children[1]->children[0]->value == "5");
    return 0;
}
