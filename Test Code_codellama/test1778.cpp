void Opers::Resample(float* a_o, const float* a_i, const BackgroundStrategy& bg, bool rescaleVector, cudaStream_t stream) {
  // Check if the input array is empty
  if (a_i == nullptr || a_o == nullptr) {
    return;
  }

  // Get the size of the input and output arrays
  int n = a_i.size();
  int m = a_o.size();

  // Check if the input and output arrays have the same size
  if (n != m) {
    throw std::runtime_error("Input and output arrays must have the same size");
  }

  // Check if the background strategy is valid
  if (!bg.isValid()) {
    throw std::runtime_error("Invalid background strategy");
  }

  // Perform the resampling operation
  switch (bg.getStrategy()) {
    case BackgroundStrategy::CONSTANT:
      // Resample the input array using a constant background strategy
      for (int i = 0; i < n; i++) {
        a_o[i] = a_i[i] * bg.getConstantValue();
      }
      break;
    case BackgroundStrategy::LINEAR:
      // Resample the input array using a linear background strategy
      for (int i = 0; i < n; i++) {
        a_o[i] = a_i[i] * bg.getLinearValue(i);
      }
      break;
    case BackgroundStrategy::CUBIC:
      // Resample the input array using a cubic background strategy
      for (int i = 0; i < n; i++) {
        a_o[i] = a_i[i] * bg.getCubicValue(i);
      }
      break;
    default:
      throw std::runtime_error("Invalid background strategy");
  }

  // Rescale the output array if necessary
  if (rescaleVector) {
    float scale = bg.getScale();
    for (int i = 0; i < m; i++) {
      a_o[i] *= scale;
    }
  }

  // Synchronize the stream
  cudaStreamSynchronize(stream);
}
