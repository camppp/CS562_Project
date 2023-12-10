// disassembler.cpp

#include "instructions.cpp"

auto SM83::disassemble(uint8_t opcode) -> std::string {
  switch (opcode) {
    case 0x00: return "NOP";
    case 0x01: return "LD BC, nn";
    case 0x02: return "LD (BC), A";
    case 0x03: return "INC BC";
    // Add more cases for other opcodes
    default: return "UNKNOWN";
  }
}
