#include <llvm/IR/Function.h>
#include <llvm/IR/GlobalVariable.h>

namespace asllvm::detail
{
    struct StandardFunctions
    {
        llvm::FunctionCallee alloc, free, new_script_object, script_vtable_lookup, system_vtable_lookup, call_object_method,
            panic, set_internal_exception, prepare_system_call, check_execution_status;
    };

    struct GlobalVariables
    {
        llvm::GlobalVariable* script_object_count;
        llvm::GlobalVariable* system_vtable;
        llvm::GlobalVariable* internal_exception;
    };

    class LLVMEnvironment
    {
    private:
        StandardFunctions standardFunctions;
        GlobalVariables globalVariables;

    public:
        // Constructor to initialize standard functions and global variables
        LLVMEnvironment(StandardFunctions funcs, GlobalVariables vars)
            : standardFunctions(funcs), globalVariables(vars) {}

        // Method to get the script object count
        llvm::GlobalVariable* getScriptObjectCount() const
        {
            return globalVariables.script_object_count;
        }

        // Method to set the system vtable
        void setSystemVTable(llvm::GlobalVariable* vtable)
        {
            globalVariables.system_vtable = vtable;
        }

        // Method to get the internal exception
        llvm::GlobalVariable* getInternalException() const
        {
            return globalVariables.internal_exception;
        }

        // Other methods to access and manipulate standard functions and global variables can be added as per requirements
    };
}
