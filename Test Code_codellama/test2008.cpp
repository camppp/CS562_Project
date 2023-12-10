void moveData(Register from, Register to) {
    if (from.getType() == RegisterType.FLOAT_REG && to.getType() == RegisterType.FLOAT_REG) {
        masm.moveDouble(from.floatReg(), to.floatReg());
    } else if (from.getType() == RegisterType.FLOAT_REG && to.getType() == RegisterType.GENERAL_REG_PAIR) {
        masm.moveFromDoubleLo(from.floatReg(), to.generalRegPair().get(0));
        masm.moveFromDoubleHi(from.floatReg(), to.generalRegPair().get(1));
    } else {
        throw new IllegalArgumentException("Invalid register types for data movement");
    }
}
