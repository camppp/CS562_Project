void PPCMCCodeEmitter::encodeInstruction(
    const MCInst &MI, raw_ostream &OS, SmallVectorImpl<MCFixup> &Fixups,
    const MCSubtargetInfo &STI) const {
  // Verify the instruction predicates
  verifyInstructionPredicates(MI, computeAvailableFeatures(STI.getFeatureBits()));

  // Obtain the binary code for the instruction and any fixups
  uint64_t Bits = getBinaryCodeForInstr(MI, Fixups, STI);

  // Determine the size of the instruction
  unsigned Size = getInstSizeInBytes(MI);

  // Output the constant in big/little endian byte order
  support::endianness E = IsLittleEndian ? support::little : support::big;
  switch (Size) {
    case 1:
      support::endian::write(OS, Bits, E);
      break;
    case 2:
      support::endian::write(OS, Bits, E);
      break;
    case 4:
      support::endian::write(OS, Bits, E);
      break;
    case 8:
      support::endian::write(OS, Bits, E);
      break;
    default:
      // Handle unsupported instruction size
      report_fatal_error("Unsupported instruction size");
  }
}
