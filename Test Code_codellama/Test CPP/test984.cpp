c
int quantize_float32_int8(float input) {
  // Round the input to the nearest integer
  int rounded_input = round(input);

  // Clamp the result to the range of an 8-bit signed integer
  int clamped_input = clamp(rounded_input, -128, 127);

  // Return the clamped result
  return clamped_input;
}
