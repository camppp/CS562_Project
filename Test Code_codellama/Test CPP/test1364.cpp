#include <string>
#include <vector>

class SExpr {
public:
    SExpr(const std::string& expr);
    std::string toString() const;
    bool isAtom() const;
    bool isList() const;
    int numElements() const;

private:
    std::string _expr;
    bool _isAtom;
    bool _isList;
    int _numElements;
};

SExpr::SExpr(const std::string& expr) : _expr(expr) {
    if (expr.empty()) {
        _isAtom = false;
        _isList = false;
        _numElements = 0;
    } else if (expr[0] == '(' && expr[expr.size() - 1] == ')') {
        _isAtom = false;
        _isList = true;
        _numElements = 0;
        for (size_t i = 1; i < expr.size() - 1; i++) {
            if (expr[i] == '(') {
                _numElements++;
            }
        }
    } else {
        _isAtom = true;
        _isList = false;
        _numElements = 0;
    }
}

std::string SExpr::toString() const {
    return _expr;
}

bool SExpr::isAtom() const {
    return _isAtom;
}

bool SExpr::isList() const {
    return _isList;
}

int SExpr::numElements() const {
    return _numElements;
}

SExpr parseSExpr(const std::string& expr) {
    return SExpr(expr);
}
