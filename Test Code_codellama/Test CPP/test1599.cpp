llvm::Value* constantFolding(llvm::Value* instruction) {
    // Check if the instruction is a constant expression
    if (instruction->isConstant()) {
        // Evaluate the constant expression
        llvm::ConstantInt* newConst = llvm::ConstantInt::get(instruction->getType(), instruction->getValue());
        return newConst;
    }

    // The instruction is not a constant expression, return the original instruction unchanged
    return instruction;
}
