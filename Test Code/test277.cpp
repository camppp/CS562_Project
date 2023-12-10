void sec_mmio_write_increment(int increment) {
  // Increment the counter in the MMIO space by the specified increment value
  sec_mmio_write32(0x1000, increment);

  // Verify that the counter was incremented correctly
  EXPECT_ABS_WRITE32(0x1000, increment);
  EXPECT_ABS_READ32(0x1000, increment);
}
