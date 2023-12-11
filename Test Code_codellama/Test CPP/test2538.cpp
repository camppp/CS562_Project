#include <fstream>
#include <iostream>
#include <string>

int countWordOccurrences(const std::string& filePath, const std::string& targetWord) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    std::cerr << "Error: unable to open file " << filePath << std::endl;
    return -1;
  }

  int count = 0;
  std::string line;
  while (std::getline(file, line)) {
    // Skip comments
    if (line.find("//") != std::string::npos) {
      continue;
    }

    // Skip string literals
    if (line.find('"') != std::string::npos) {
      continue;
    }

    // Check if the target word is in the line
    if (line.find(targetWord) != std::string::npos) {
      count++;
    }
  }

  return count;
}
