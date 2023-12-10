class AotStmtVisitor {
public:
    void VisitBreakStmt(natRefPointer<Statement::BreakStmt> const& stmt) {
        assert(!m_BreakContinueStack.empty() && "break not in a breakable scope");
        const auto dest = m_BreakContinueStack.back().first;
        assert(dest.GetBlock());
        // Process the "break" statement within the AST
        // ...
    }

    void VisitIfStmt(natRefPointer<Statement::IfStmt> const& stmt) {
        // Process the "if" statement within the AST
        // ...
    }

    void VisitWhileStmt(natRefPointer<Statement::WhileStmt> const& stmt) {
        // Process the "while" statement within the AST
        // ...
    }

    void VisitReturnStmt(natRefPointer<Statement::ReturnStmt> const& stmt) {
        // Process the "return" statement within the AST
        // ...
    }

    void VisitExpressionStmt(natRefPointer<Statement::ExpressionStmt> const& stmt) {
        // Process the "expression" statement within the AST
        // ...
    }

private:
    // Additional member variables and helper methods can be included as needed
    // ...
};
