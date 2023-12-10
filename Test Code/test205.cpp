#include <iostream>
#include <string>
#include <vector>

std::string extractCopyright(const std::string& sourceCode) {
  // Split the source code into lines
  std::vector<std::string> lines = split(sourceCode, "\n");

  // Iterate over the lines and look for copyright notices
  for (const std::string& line : lines) {
    // Check if the line starts with a comment
    if (line.starts_with("//")) {
      // Extract the copyright notice from the comment
      std::string copyright = line.substr(2);
      // Remove any leading or trailing whitespace
      copyright = trim(copyright);
      // Return the copyright notice
      return copyright;
    }
  }

  // If no copyright notice was found, return an empty string
  return "";
}

// Helper function to split a string into a vector of substrings
std::vector<std::string> split(const std::string& str, const std::string& delim) {
  std::vector<std::string> result;
  size_t pos = 0;
  while ((pos = str.find(delim)) != std::string::npos) {
    result.push_back(str.substr(0, pos));
    str = str.substr(pos + delim.length());
  }
  result.push_back(str);
  return result;
}

// Helper function to trim leading and trailing whitespace
std::string trim(const std::string& str) {
  std::string result = str;
  result.erase(std::remove_if(result.begin(), result.end(), [](char c) {
    return std::isspace(c);
  }), result.end());
  return result;
}
