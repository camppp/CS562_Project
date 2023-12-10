void performDataCopy(torch::Tensor input, std::vector<int>& buffer_, int& numAdd_) {
  // Obtain the indices for copying data
  torch::Tensor tensorIndices = getNextIndices(input);
  numAdd_ += tensorIndices.size(0);

  // Iterate through the buffer and perform the copying
  for (auto& index : tensorIndices.accessor<int, 1>()) {
    int idx = index.item<int>();
    if (idx >= 0 && idx < input.size(0)) {
      buffer_[idx] = input[idx].item<int>();
    }
  }
}
