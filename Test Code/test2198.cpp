#include <iostream>

// Define the segment selectors
#define KERNEL_CS 0x08

// Define the interrupt descriptor table entry structure
struct idt_entry_t {
    uint16_t offset_low;
    uint16_t segment_selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;

    void set(uint16_t seg_selector, void (*handler)(), uint8_t type, uint8_t privilege_level) {
        offset_low = (uint32_t)handler & 0xFFFF;
        offset_high = ((uint32_t)handler >> 16) & 0xFFFF;
        segment_selector = seg_selector;
        zero = 0;
        type_attr = (type << 4) | (privilege_level & 0x3);
    }
};

// Define the interrupt descriptor table class
class interrupt_descriptor_table_t {
public:
    static interrupt_descriptor_table_t& instance() {
        static interrupt_descriptor_table_t interrupts_table;
        return interrupts_table;
    }

    void register_isr(uint8_t n, void (*handler)(), uint8_t type) {
        idt_entries[n].set(KERNEL_CS, handler, type, 3);
    }

    void register_irq(uint8_t n, void (*handler)()) {
        idt_entries[n].set(KERNEL_CS, handler, idt_entry_t::interrupt_gate, 0);
    }

private:
    idt_entry_t idt_entries[256];
};

// Define the interrupt service routines (ISRs)
void isr0() {
    std::cout << "ISR 0 called" << std::endl;
    // Handle ISR 0
}

void isr1() {
    std::cout << "ISR 1 called" << std::endl;
    // Handle ISR 1
}

// Define the interrupt request handlers (IRQs)
void irq0() {
    std::cout << "IRQ 0 called" << std::endl;
    // Handle IRQ 0
}

void irq1() {
    std::cout << "IRQ 1 called" << std::endl;
    // Handle IRQ 1
}

int main() {
    // Register ISRs and IRQs using the IDT
    interrupt_descriptor_table_t::instance().register_isr(0, isr0, idt_entry_t::interrupt_gate);
    interrupt_descriptor_table_t::instance().register_isr(1, isr1, idt_entry_t::interrupt_gate);
    interrupt_descriptor_table_t::instance().register_irq(0, irq0);
    interrupt_descriptor_table_t::instance().register_irq(1, irq1);

    // Simulate interrupt/exception triggering
    // ...

    return 0;
}
