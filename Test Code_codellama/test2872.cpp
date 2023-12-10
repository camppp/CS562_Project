std::list<ExpressionRef> processExpressions(const std::list<ExpressionRef>& unitList, ScriptCompiler* scriptCompiler) {
    if (unitList.empty()) {
        scriptCompiler->setErrorText("Incomplete expression");
        return {};
    }

    auto lastExpression = unitList.back();
    if (lastExpression->back() != ';') {
        scriptCompiler->setErrorText("Missing semicolon");
        return {};
    }

    // Remove the last semicolon from the last expression
    lastExpression->pop_back();

    // Modify the list of expressions to remove the last semicolon
    std::list<ExpressionRef> modifiedList;
    for (auto& expression : unitList) {
        if (expression == lastExpression) {
            modifiedList.push_back(expression);
        } else {
            modifiedList.push_back(expression->substr(0, expression->size() - 1));
        }
    }

    return modifiedList;
}
