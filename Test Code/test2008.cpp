java
void moveData(Register from, Register to) {
    if (from.getType() == RegisterType.FLOAT_REG && to.getType() == RegisterType.FLOAT_REG) {
        masm.moveDouble(from.getFloatReg(), to.getFloatReg());
    } else if (from.getType() == RegisterType.FLOAT_REG && to.getType() == RegisterType.GENERAL_REG_PAIR) {
        // Used for passing double parameter in a2,a3 register pair.
        // Two moves are added for one double parameter by
        // MacroAssembler::passABIArg
        MOZ_ASSERT(to.getEvenReg() == "a2" && to.getOddReg() == "a3", "Invalid emitDoubleMove arguments.");
        masm.moveFromDoubleLo(from.getFloatReg(), "a2");
        masm.moveFromDoubleHi(from.getFloatReg(), "a3");
    }
}
