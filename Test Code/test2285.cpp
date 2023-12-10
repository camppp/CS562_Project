#include <vector>
#include <memory>
#include "PDBSymbolFunc.h"
#include "PDBSymbolData.h"

class SymbolManager {
private:
    struct SymbolGroup {
        std::vector<std::unique_ptr<PDBSymbolFunc>> Functions;
        std::vector<std::unique_ptr<PDBSymbolData>> Data;
    };

    SymbolGroup AccessGroup;

public:
    void pushFunction(std::unique_ptr<PDBSymbolFunc> Func) {
        AccessGroup.Functions.push_back(std::move(Func));
    }

    void pushData(std::unique_ptr<PDBSymbolData> Data) {
        AccessGroup.Data.push_back(std::move(Data));
    }

    size_t getFunctionCount() const {
        return AccessGroup.Functions.size();
    }

    size_t getDataCount() const {
        return AccessGroup.Data.size();
    }
};
