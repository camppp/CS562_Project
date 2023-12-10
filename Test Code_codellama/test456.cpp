#include <llvm/Instruction.h>

class Reader {
public:
    // Check if the given LLVM instruction exists in the reader
    bool has(const llvm::Instruction &CurInstruction) const {
        return CurInstruction.isValid();
    }
};
