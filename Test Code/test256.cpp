#include <iostream>
#include <vector>
#include <string>

// Function to trim the first element from a vector of strings
std::vector<std::string> trim(const std::vector<std::string>& v, size_t start, size_t end) {
    std::vector<std::string> trimmed;
    for (size_t i = start; i < end; ++i) {
        trimmed.push_back(v[i]);
    }
    return trimmed;
}

// Function to find the block tail
// Assume the implementation of find_block_tail is provided elsewhere
void find_block_tail(const std::vector<std::string>& v_formula) {
    // Implementation of find_block_tail
}

// Function to process the formula
void processFormula(std::vector<std::string>& v_formula, double& val) {
    if (!v_formula.empty() && v_formula[0] == "-") {
        v_formula = trim(v_formula, 1, v_formula.size());
        val = -val;
    }
    find_block_tail(v_formula);
}

int main() {
    // Example usage
    std::vector<std::string> formula = {"-", "5", "+", "3"};
    double value = 10.0;
    processFormula(formula, value);
    // After processing, formula will be {"5", "+", "3"} and value will be -10.0
    return 0;
}
