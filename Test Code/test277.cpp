void sec_mmio_write_increment(int increment) {
  // Increment the counter in the MMIO space by the specified value
  for (int i = 0; i < increment; ++i) {
    sec_mmio_write32(0, sec_mmio_read32(0) + 1);
  }
  ctx_->write_count += increment;
  ctx_->last_index++;
  ctx_->expected_write_count += increment;
}
