#include "vm.hpp"
#include <pomagma/atlas/vm_impl.hpp>

void executeInstruction(Opcode opcode, Operand* operands) {
    switch (opcode) {
        case LOAD: {
            // Load value from memory into a register
            int memoryAddress = operands[0];
            int registerIndex = operands[1];
            registers[registerIndex] = memory[memoryAddress];
            break;
        }
        case STORE: {
            // Store value from a register into memory
            int registerIndex = operands[0];
            int memoryAddress = operands[1];
            memory[memoryAddress] = registers[registerIndex];
            break;
        }
        case ADD: {
            // Add two values from registers and store the result in another register
            int reg1 = operands[0];
            int reg2 = operands[1];
            int resultReg = operands[2];
            registers[resultReg] = registers[reg1] + registers[reg2];
            break;
        }
        case SUB: {
            // Subtract one value from another and store the result in a register
            int reg1 = operands[0];
            int reg2 = operands[1];
            int resultReg = operands[2];
            registers[resultReg] = registers[reg1] - registers[reg2];
            break;
        }
        case MUL: {
            // Multiply two values from registers and store the result in another register
            int reg1 = operands[0];
            int reg2 = operands[1];
            int resultReg = operands[2];
            registers[resultReg] = registers[reg1] * registers[reg2];
            break;
        }
        case DIV: {
            // Divide one value by another and store the result in a register
            int reg1 = operands[0];
            int reg2 = operands[1];
            int resultReg = operands[2];
            if (registers[reg2] != 0) {
                registers[resultReg] = registers[reg1] / registers[reg2];
            } else {
                // Handle division by zero error
                // For example, set a flag or raise an exception
            }
            break;
        }
        default: {
            // Handle unknown opcode error
            // For example, set a flag or raise an exception
            break;
        }
    }
}
