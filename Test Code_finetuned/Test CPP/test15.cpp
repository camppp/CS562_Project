void HandleInterrupt(int value, bool irqAsserted, int& statusRegister, int& index) {
    const int GS_CLEAR_STS = 0x1;

    if (irqAsserted) {
        // Invoke the ISR
        m_irq->Handle(0);

        // Update the status register and index
        if (value & GS_CLEAR_STS) {
            statusRegister = 0;
            index = 0;
        } else {
            // Assuming the status register is a bitfield where each bit represents a different condition
            // and the index is the position of the bit that needs to be set
            statusRegister |= (1 << index);
        }
    }
}