#include <iostream>

namespace asllvm::detail {

struct StandardFunctions {
    void* script_object_count;
    void* system_vtable;
    void* internal_exception;
};

struct GlobalVariables {
    void* script_object_count;
    void* system_vtable;
    void* internal_exception;
};

class LLVMEnvironment {
public:
    LLVMEnvironment(StandardFunctions& standardFunctions, GlobalVariables& globalVariables)
        : standardFunctions(standardFunctions), globalVariables(globalVariables) {}

    void setScriptObjectCount(int count) {
        globalVariables.script_object_count = count;
    }

    int getScriptObjectCount() {
        return globalVariables.script_object_count;
    }

    void setSystemVtable(void* vtable) {
        globalVariables.system_vtable = vtable;
    }

    void* getSystemVtable() {
        return globalVariables.system_vtable;
    }

    void setInternalException(void* exception) {
        globalVariables.internal_exception = exception;
    }

    void* getInternalException() {
        return globalVariables.internal_exception;
    }

private:
    StandardFunctions& standardFunctions;
    GlobalVariables& globalVariables;
};

} // namespace asllvm::detail
