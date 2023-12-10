int memoryMapping(bool condition) {
  int programMemoryBank = 0;
  int characterMemoryBank = 0;

  if (condition) {
    programMemoryBank = 0x20;
    characterMemoryBank = 0x00;
  } else {
    programMemoryBank = 0x07;
    characterMemoryBank = 0x00;
  }

  return programMemoryBank, characterMemoryBank;
}
