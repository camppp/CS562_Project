#include "instructions.cpp"
#include "serialization.cpp"
#include "disassembler.cpp"

auto SM83::disassemble(uint16_t opcode) -> string {
  // Get the instruction mnemonic from the opcode
  string mnemonic = instructions[opcode];

  // If the mnemonic is not found, return an error message
  if (mnemonic.empty()) {
    return "Invalid opcode: " + to_string(opcode);
  }

  // Deserialize the operands from the opcode
  vector<uint8_t> operands = deserialize_operands(opcode);

  // Build the assembly language instruction
  string instruction = mnemonic + " " + to_string(operands[0]);
  if (operands.size() > 1) {
    instruction += ", " + to_string(operands[1]);
  }

  return instruction;
}
