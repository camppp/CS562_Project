int processFiles(FileReader* reader, const string& password, const vector<string>& filePaths) {
  for (int i = 0; i < filePaths.size(); i++) {
    const string& filePath = filePaths[i];
    const size_t size = static_cast<size_t>(reader->GetFileSize(filePath));
    if (size == 0) {
      // Skip directories and empty files.
      continue;
    }

    if (!reader->OpenFile(password, filePath)) {
      return i;
    }
  }

  return -1;
}
