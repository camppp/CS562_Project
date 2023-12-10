java
public class InstructionBuilder {
    public Instruction BuildInstruction(String instructionStr, Processor processor) {
        String[] parts = instructionStr.split(" ");
        String opcode = parts[0];
        String[] operands = parts[1].split(",");

        // Create a new instruction object based on the parsed information
        Instruction newInstruction = new Instruction(opcode, operands[0], operands[1]);

        // Update processor's registers and flags based on the operation
        switch (opcode) {
            case "CMP":
                int operand1 = Integer.parseInt(operands[0].substring(1)); // Extract the register number
                int operand2 = Integer.parseInt(operands[1].substring(1)); // Extract the immediate value
                int result = processor.GetProcessRegisters().GetRegisterValue(operand1) - operand2;
                processor.GetProcessRegisters().SetZeroFlag(result == 0);
                processor.GetProcessRegisters().SetCarryFlag(result < 0);
                processor.GetProcessRegisters().SetOverflowFlag(false); // Assuming no overflow for simplicity
                break;
            // Handle other opcodes and their respective register and flag updates
        }

        return newInstruction;
    }
}
