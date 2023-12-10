int quantize_float32_int8(float input) {
  // Quantize the floating-point number to the nearest integer
  int quantized_value = (int)(input + 0.5f);

  // Clamp the quantized value within the range of an 8-bit signed integer
  if (quantized_value > 127) {
    return 127;
  } else if (quantized_value < -128) {
    return -128;
  } else {
    return quantized_value;
  }
}
