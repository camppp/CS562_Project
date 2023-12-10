#include <vector>

class CncFun {
    // Implementation of CncFun class
};

class CncType {
    // Implementation of CncType class
};

class AppResult {
private:
    CncFun* cncFun;
    CncType* cncType;
    std::vector<CncType*> cncTypes;

public:
    CncFun* getConcreteFunction() const {
        return cncFun;
    }

    CncType* getConcreteType() const {
        return cncType;
    }

    const std::vector<CncType*>& getConcreteTypes() const {
        return cncTypes;
    }
};
