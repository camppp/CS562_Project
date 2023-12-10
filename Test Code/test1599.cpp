llvm::Value* constantFolding(llvm::Value* instruction) {
    if (llvm::Constant *C = llvm::dyn_cast<llvm::Constant>(instruction)) {
        // If the instruction is a constant expression, evaluate it
        llvm::Constant *folded = llvm::ConstantFoldConstant(C, module->getDataLayout());
        if (folded) {
            return folded;
        }
    }
    // If the instruction is not a constant expression, return the original instruction
    return instruction;
}
