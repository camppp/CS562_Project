#include <string>
#include <vector>
#include <algorithm>

std::string convertToQuotedFormat(const std::string& input_string) {
  std::vector<std::string> words;
  std::stringstream ss(input_string);
  std::string word;
  while (ss >> word) {
    words.push_back(word);
  }

  std::string result;
  for (const auto& word : words) {
    result += "\"" + word + "\"";
    if (&word != &words.back()) {
      result += ", ";
    }
  }

  return result;
}
