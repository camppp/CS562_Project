void HandleInterrupt(int value, bool irqAsserted, int& statusRegister, int& index) {
    // Check if the interrupt request line is asserted
    if (irqAsserted) {
        // Invoke the ISR
        m_irq->Handle(0);
    }

    // Check if the GS_CLEAR_STS bit is set
    if (value & GS_CLEAR_STS) {
        // Clear the status register
        statusRegister = 0;
    }

    // Update the index based on the status register value
    index = value & 0xFF;
}
