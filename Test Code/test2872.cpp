#include <list>
#include <string>
#include <memory>

class ScriptCompiler {
public:
    static bool isCommandBreakSign(char c) {
        return c == ';';
    }

    void setErrorText(const std::string& error) {
        // Implementation not provided
    }
};

using ExpressionRef = std::shared_ptr<std::string>;

std::list<ExpressionRef> processExpressions(const std::list<ExpressionRef>& unitList, ScriptCompiler* scriptCompiler) {
    if (unitList.empty()) {
        scriptCompiler->setErrorText("incomplete expression");
        return {};
    }

    const std::string& lastExpression = *unitList.back();
    if (lastExpression.empty() || !ScriptCompiler::isCommandBreakSign(lastExpression.back())) {
        scriptCompiler->setErrorText("missing ';'");
        return {};
    }

    return unitList;  // Return the original list of expressions if all conditions are met
}
