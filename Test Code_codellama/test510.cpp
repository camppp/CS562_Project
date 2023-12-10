class TreeProcessor {
public:
  void ProcessEntry(int entryNumber) {
    // Load the object from the tree for the given entry number
    auto object = LoadObjectFromTree(entryNumber);

    // Perform analysis on the loaded object
    // ...

    // Fill histograms with the results of the analysis
    // ...

    // Check if the processing should be aborted
    if (Abort()) {
      // Stop the processing
      return;
    }
  }

  void Abort() {
    // Set a flag to indicate that the processing should be aborted
    abort_ = true;
  }

private:
  bool abort_ = false;
};
