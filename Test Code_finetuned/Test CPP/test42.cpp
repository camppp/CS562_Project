#include <iostream>

namespace asllvm::detail {

struct StandardFunctions {
    // Assume these are function pointers
    void (*script_object_count)();
    void (*system_vtable)();
    void (*internal_exception)();
};

struct GlobalVariables {
    int script_object_count;
    void* system_vtable;
    void* internal_exception;
};

class LLVMEnvironment {
private:
    StandardFunctions standard_functions;
    GlobalVariables global_variables;

public:
    LLVMEnvironment(StandardFunctions standard_functions, GlobalVariables global_variables)
        : standard_functions(standard_functions), global_variables(global_variables) {}

    void callScriptObjectCount() {
        standard_functions.script_object_count();
    }

    void callSystemVTable() {
        standard_functions.system_vtable();
    }

    void callInternalException() {
        standard_functions.internal_exception();
    }

    int getScriptObjectCount() {
        return global_variables.script_object_count;
    }

    void* getSystemVTable() {
        return global_variables.system_vtable;
    }

    void* getInternalException() {
        return global_variables.internal_exception;
    }

    void setScriptObjectCount(int count) {
        global_variables.script_object_count = count;
    }

    void setSystemVTable(void* vtable) {
        global_variables.system_vtable = vtable;
    }

    void setInternalException(void* exception) {
        global_variables.internal_exception = exception;
    }
};

} // namespace asllvm::detail