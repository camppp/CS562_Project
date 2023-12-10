c
void setContrastLevel(uint8_t contrastLevel) {
  // Ensure that the contrast level does not exceed the maximum allowed value
  if (contrastLevel > 0x7f) {
    contrastLevel = 0x7f;
  }

  // Set the contrast level
  writeCommand(0x81);
  writeData(contrastLevel);

  // Configure the display to normal mode
  writeCommand(0x00);
  writeData(0x00);

  // Set the display to normal
  writeCommand(0x00);
  writeData(0x00);
}
