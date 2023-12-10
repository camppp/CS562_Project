#include <iostream>
#include <cstdint>

// Define the IDT entry structure
struct idt_entry_t {
    uint16_t segment_selector;
    uint16_t offset_low;
    uint16_t offset_high;
    uint8_t type;
    uint8_t privilege_level;
};

// Define the IDT class
class interrupt_descriptor_table_t {
public:
    // Singleton instance method
    static interrupt_descriptor_table_t& instance() {
        static interrupt_descriptor_table_t instance;
        return instance;
    }

    // Set up the IDT entry for an ISR
    #define IDT_ENTRY(isr_number, segment_selector, offset, type, privilege_level) \
        idt_entry_t isr_##isr_number = {segment_selector, offset, type, privilege_level}; \
        idt_entries[isr_number] = isr_##isr_number;

    // Set up the IDT entry for an IRQ
    #define IRQ_ENTRY(irq_number, segment_selector, offset, type, privilege_level) \
        idt_entry_t irq_##irq_number = {segment_selector, offset, type, privilege_level}; \
        idt_entries[irq_number] = irq_##irq_number;

    // Define the ISRs and IRQs
    void isr0() {
        std::cout << "ISR 0 called" << std::endl;
    }

    void isr1() {
        std::cout << "ISR 1 called" << std::endl;
    }

    void irq0() {
        std::cout << "IRQ 0 called" << std::endl;
    }

    void irq1() {
        std::cout << "IRQ 1 called" << std::endl;
    }

private:
    // Define the IDT entries
    idt_entry_t idt_entries[256];
};

// Define the ISRs and IRQs
void isr0() {
    interrupt_descriptor_table_t::instance().isr0();
}

void isr1() {
    interrupt_descriptor_table_t::instance().isr1();
}

void irq0() {
    interrupt_descriptor_table_t::instance().irq0();
}

void irq1() {
    interrupt_descriptor_table_t::instance().irq1();
}

// Register the ISRs and IRQs
IDT_ENTRY(0, 0x08, 0x00, 0x8E, 0x00);
IDT_ENTRY(1, 0x10, 0x00, 0x8E, 0x00);
IRQ_ENTRY(0, 0x20, 0x00, 0x8E, 0x00);
IRQ_ENTRY(1, 0x28, 0x00, 0x8E, 0x00);

int main() {
    // Register the ISRs and IRQs
    asm("lidt (%0)" : : "r" (&interrupt_descriptor_table_t::instance()));

    // Trigger an interrupt
    asm("int $0x00");

    return 0;
}
