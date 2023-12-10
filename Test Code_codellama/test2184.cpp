void performDataCopy(torch::Tensor input, std::vector<int> buffer, int& numAdd) {
  // Obtain the indices for copying data from the input tensor
  std::vector<int> indices = getNextIndices(input);

  // Increment the numAdd variable by the size of the obtained indices
  numAdd += indices.size();

  // Iterate through the buffer vector and copy the data from the input tensor to the buffer based on the obtained indices
  for (int i = 0; i < indices.size(); i++) {
    buffer[i] = input[indices[i]];
  }
}
