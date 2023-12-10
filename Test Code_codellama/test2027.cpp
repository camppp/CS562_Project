bool processBlocks(const std::vector<Block>& blocks, const Settings& settings) {
  // Check if the data is preloaded
  if (settings.low_memory) {
    // Set the vec, list, and bitmap attributes of both blocks to nullptr
    for (auto& block : blocks) {
      block.vec = nullptr;
      block.list = nullptr;
      block.bitmap = nullptr;
    }
  }

  // Calculate the total number of records in the two blocks
  int total_records = blocks[0].n_rec + blocks[1].n_rec;

  // Update the progress by adding the product of the number of records in the two blocks to the n_var attribute of the progress object
  progress.n_var += total_records;

  // For each record i in the first block and each record j in the second block, call a function f on the engine with the corresponding records and a performance parameter perf
  for (int i = 0; i < blocks[0].n_rec; i++) {
    for (int j = 0; j < blocks[1].n_rec; j++) {
      // Call the function f on the engine with the corresponding records and a performance parameter perf
      f(blocks[0].vec[i], blocks[1].vec[j], perf);
    }
  }

  // Return true if the processing is successful
  return true;
}
