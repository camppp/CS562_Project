#include <llvm/Instruction.h>
#include <unordered_set>

class Reader {
private:
    std::unordered_set<const llvm::Instruction*> instructionSet;

public:
    // Add an LLVM instruction to the reader
    void addInstruction(const llvm::Instruction &instruction) {
        instructionSet.insert(&instruction);
    }

    // Check if the given LLVM instruction exists in the reader
    bool has(const llvm::Instruction &CurInstruction) const {
        return instructionSet.find(&CurInstruction) != instructionSet.end();
    }
};
