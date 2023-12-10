void HandleInterrupt(int value, bool irqAsserted, int& statusRegister, int& index) {
    if (irqAsserted) {
        // Invoke ISR
        m_irq->Handle(0);
    }

    if (value & GS_CLEAR_STS) {
        // Clear status register and index
        statusRegister = 0;
        index = 0;
    }
}
