#include "vm.hpp"
#include <pomagma/atlas/vm_impl.hpp>

void executeInstruction(Opcode opcode, Operand* operands) {
    switch (opcode) {
        case LOAD: {
            // Load a value from memory into a register
            uint32_t reg = operands[0];
            uint32_t mem = operands[1];
            registers[reg] = memory[mem];
            break;
        }
        case STORE: {
            // Store a value from a register into memory
            uint32_t reg = operands[0];
            uint32_t mem = operands[1];
            memory[mem] = registers[reg];
            break;
        }
        case ADD: {
            // Add two values from registers and store the result in another register
            uint32_t reg1 = operands[0];
            uint32_t reg2 = operands[1];
            uint32_t reg3 = operands[2];
            registers[reg3] = registers[reg1] + registers[reg2];
            break;
        }
        case SUB: {
            // Subtract one value from another and store the result in a register
            uint32_t reg1 = operands[0];
            uint32_t reg2 = operands[1];
            uint32_t reg3 = operands[2];
            registers[reg3] = registers[reg1] - registers[reg2];
            break;
        }
        case MUL: {
            // Multiply two values from registers and store the result in another register
            uint32_t reg1 = operands[0];
            uint32_t reg2 = operands[1];
            uint32_t reg3 = operands[2];
            registers[reg3] = registers[reg1] * registers[reg2];
            break;
        }
        case DIV: {
            // Divide one value by another and store the result in a register
            uint32_t reg1 = operands[0];
            uint32_t reg2 = operands[1];
            uint32_t reg3 = operands[2];
            registers[reg3] = registers[reg1] / registers[reg2];
            break;
        }
        default: {
            // Unknown opcode
            break;
        }
    }
}
