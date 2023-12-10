#include <iostream>
#include <vector>

// Forward declaration for the Expression class
class Expression;

// Forward declaration for the Statement class
class Statement;

class WhileStmt {
private:
    std::vector<Statement*> inits;
    Expression* cond;
    Statement* stmt;

public:
    // Constructor to initialize the attributes
    WhileStmt(std::vector<Statement*> inits, Expression* cond, Statement* stmt)
        : inits(inits), cond(cond), stmt(stmt) {}

    // Method to print information about the while loop statement and its components
    void dump(int indent) const {
        // Function to generate spaces based on the indent level
        auto spaces = [](int count) {
            return std::string(count, ' ');
        };

        // Print the type of the statement and its memory address
        std::cout << spaces(indent) << "WhileStmt " << this << " <" << m_loc << ">\n";

        // Recursively call the dump method for each initialization statement in the inits vector
        for (auto& init : inits) {
            init->dump(indent + 2);
        }

        // Call the dump method for the condition expression if it exists
        if (cond) {
            cond->dump(indent + 2);
        }

        // Call the dump method for the body of the while loop if it exists
        if (stmt) {
            stmt->dump(indent + 2);
        }
    }
};

// Example usage
int main() {
    // Create an instance of WhileStmt with dummy data
    WhileStmt whileStmt({/* initialization statements */}, /* condition expression */, /* body statement */);

    // Call the dump method to print information about the while loop statement
    whileStmt.dump(0);

    return 0;
}
