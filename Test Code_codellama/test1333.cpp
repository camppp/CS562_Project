output_type dac_top(input_type in, bool valid) {
  // Perform digital-to-analog conversion based on input signal and validity flag
  output_type out;
  if (valid) {
    out = in * 2.0 - 1.0;  // Convert digital input to analog output
  } else {
    out = 0.0;  // Return 0 if input is invalid
  }
  return out;
}
