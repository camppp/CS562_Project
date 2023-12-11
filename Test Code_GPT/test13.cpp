#include <iostream>

// Assuming the GS_CLEAR_STS bit is defined as a specific bit position
#define GS_CLEAR_STS (1 << 3)

void HandleInterrupt(int value, bool irqAsserted, int& statusRegister, int& index) {
    if (irqAsserted) {
        // If IRQ is asserted, call ISR
        // For illustration purposes, print a message
        std::cout << "ISR called" << std::endl;

        // Update the status register based on GS_CLEAR_STS bit
        if (value & GS_CLEAR_STS) {
            statusRegister = 0;
            std::cout << "Status Register cleared" << std::endl;
        } else {
            // Update the status register with the provided value
            statusRegister = value;
            std::cout << "Status Register updated with value: " << value << std::endl;
        }

        // Update the index based on the provided value
        index = value & 0x03;
        std::cout << "Index updated with value: " << index << std::endl;
    } else {
        std::cout << "No interrupt asserted" << std::endl;
    }
}

int main() {
    // Example usage
    int statusRegister = 0;
    int index = 0;

    // Simulate an interrupt request with value 0x0A and GS_CLEAR_STS bit set
    HandleInterrupt(0x0A | GS_CLEAR_STS, true, statusRegister, index);

    // Simulate an interrupt request with value 0x05 and GS_CLEAR_STS bit not set
    HandleInterrupt(0x05, true, statusRegister, index);

    // Simulate no interrupt request
    HandleInterrupt(0, false, statusRegister, index);

    return 0;
}
