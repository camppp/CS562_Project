void setContrastLevel(uint8_t contrastLevel) {
  // Cap the contrast level if it exceeds the maximum allowed value
  if (contrastLevel > 0x7f) {
    contrastLevel = 0x7f;
  }

  // Set the contrast level using the PCD8544_SETVOP command
  command(PCD8544_SETVOP | contrastLevel); // Experimentally determined

  // Configure the display to normal mode using the PCD8544_FUNCTIONSET command
  command(PCD8544_FUNCTIONSET);

  // Set the display to normal using the PCD8544_DISPLAYCONTROL command
  command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
}
