class AotStmtVisitor {
public:
    void VisitBreakStmt(BreakStmt* stmt) {
        // Check if the break statement is within a breakable scope
        if (!stmt->IsWithinBreakableScope()) {
            // Error: break statement is not within a breakable scope
            return;
        }

        // Determine the destination block for the break statement
        Block* destBlock = stmt->GetDestinationBlock();

        // Process the break statement
        destBlock->AddBreakStatement(stmt);
    }

    void VisitIfStmt(IfStmt* stmt) {
        // Process the condition of the if statement
        Expression* cond = stmt->GetCondition();
        if (cond->IsConstant()) {
            // Constant condition: evaluate the condition and process the if statement
            if (cond->GetConstantValue()) {
                // Condition is true: process the if statement
                stmt->GetThenBlock()->Accept(this);
            } else {
                // Condition is false: process the else statement
                stmt->GetElseBlock()->Accept(this);
            }
        } else {
            // Non-constant condition: add the if statement to the current block
            GetCurrentBlock()->AddStatement(stmt);
        }
    }

    void VisitWhileStmt(WhileStmt* stmt) {
        // Process the condition of the while statement
        Expression* cond = stmt->GetCondition();
        if (cond->IsConstant()) {
            // Constant condition: evaluate the condition and process the while statement
            if (cond->GetConstantValue()) {
                // Condition is true: process the while statement
                stmt->GetBodyBlock()->Accept(this);
            }
        } else {
            // Non-constant condition: add the while statement to the current block
            GetCurrentBlock()->AddStatement(stmt);
        }
    }

    void VisitReturnStmt(ReturnStmt* stmt) {
        // Process the return statement
        Expression* expr = stmt->GetExpression();
        if (expr != nullptr) {
            // Return expression is not null: evaluate the expression and process the return statement
            expr->Accept(this);
        } else {
            // Return expression is null: process the return statement
            stmt->GetBlock()->Accept(this);
        }
    }

    void VisitExpressionStmt(ExpressionStmt* stmt) {
        // Process the expression statement
        Expression* expr = stmt->GetExpression();
        expr->Accept(this);
    }

private:
    Block* GetCurrentBlock() {
        // Return the current block
        return nullptr;
    }
};
