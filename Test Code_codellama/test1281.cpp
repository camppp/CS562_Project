template <typename DType>
void cbFunction(const DType* src, DType* dst, int H, int W, int K, int S, int P, int D, cudaStream_t stream) {
  // Check if the data type of the source layout matches DType
  if (src->type() == DType::type()) {
    // Perform the specific operation using the mask_conv::mask_propagate_exec_proxy function
    mask_conv::mask_propagate_exec_proxy(src, dst, H, W, K, S, P, D, stream);
  }
}
