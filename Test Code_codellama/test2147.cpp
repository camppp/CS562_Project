Processor* BuildInstruction(const string& instruction, Processor* processor) {
    // Parse the instruction string
    vector<string> tokens = split(instruction, ",");
    string opcode = tokens[0];
    string operand1 = tokens[1];
    string operand2 = tokens[2];

    // Create a new instruction object
    Instruction* pInstruction = new Instruction(opcode, operand1, operand2);

    // Update the processor's registers and flags based on the operation
    switch (opcode) {
        case "ADD":
            processor->setRegister(operand1, processor->getRegister(operand1) + processor->getRegister(operand2));
            processor->setFlag(FLAG_ZERO, processor->getRegister(operand1) == 0);
            break;
        case "SUB":
            processor->setRegister(operand1, processor->getRegister(operand1) - processor->getRegister(operand2));
            processor->setFlag(FLAG_ZERO, processor->getRegister(operand1) == 0);
            break;
        case "CMP":
            processor->setRegister(operand1, processor->getRegister(operand1) - processor->getRegister(operand2));
            processor->setFlag(FLAG_ZERO, processor->getRegister(operand1) == 0);
            break;
        default:
            throw runtime_error("Invalid opcode");
    }

    // Return the new instruction object
    return pInstruction;
}
