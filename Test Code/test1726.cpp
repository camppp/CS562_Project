#include <vector>
#include <string>

class FileReader {
public:
  bool OpenFile(const std::string& password) {
    // Implementation of file opening with password
    return true;  // Replace with actual implementation
  }

  long GetFileSize() {
    // Implementation of getting file size
    return 0;  // Replace with actual implementation
  }
};

int processFiles(FileReader* reader, const std::string& password, const std::vector<std::string>& filePaths) {
  for (size_t i = 0; i < filePaths.size(); ++i) {
    const size_t size = static_cast<size_t>(reader->GetFileSize());
    if (size == 0) {
      // Skip directories and empty files.
      continue;
    }

    if (!reader->OpenFile(password))
      return static_cast<int>(i);  // Return the index of the file path that failed to open
  }
  return -1;  // All files were successfully processed
}
