bool simulateCPU(int steps, CPU c) {
    for (int i = 0; i < steps; i++) {
        cpu_step(c);
        if (c.registers.pc == 0x017E) {
            return true;
        }
    }
    return false;
}
