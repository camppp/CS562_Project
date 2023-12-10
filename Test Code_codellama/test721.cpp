void encodeInstruction(const MCInst &MI, raw_ostream &OS,
                       SmallVectorImpl<MCFixup> &Fixups,
                       const MCSubtargetInfo &STI) {
  // Verify the instruction predicates.
  verifyInstructionPredicates(MI, STI);

  // Compute the available features.
  uint64_t AvailableFeatures = computeAvailableFeatures(STI);

  // Obtain the binary code for the instruction and any fixups.
  std::vector<uint8_t> BinaryCode = getBinaryCodeForInstr(MI, Fixups, STI);

  // Determine the size of the instruction.
  uint64_t InstSize = getInstSizeInBytes(MI);

  // Output the binary code in big or little endian format based on the size of the instruction.
  if (InstSize == 4) {
    if (IsLittleEndian)
      support::endianness::write<uint32_t>(BinaryCode.data(), OS, support::endianness::little);
    else
      support::endianness::write<uint32_t>(BinaryCode.data(), OS, support::endianness::big);
  } else if (InstSize == 8) {
    if (IsLittleEndian)
      support::endianness::write<uint64_t>(BinaryCode.data(), OS, support::endianness::little);
    else
      support::endianness::write<uint64_t>(BinaryCode.data(), OS, support::endianness::big);
  } else {
    llvm_unreachable("Unsupported instruction size");
  }
}
