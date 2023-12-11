#include <string>
#include <vector>

std::string reverseWords(const std::string& input) {
  std::vector<std::string> words;
  std::stringstream ss(input);
  std::string word;
  while (ss >> word) {
    words.push_back(word);
  }
  std::string result;
  for (int i = words.size() - 1; i >= 0; i--) {
    result += words[i];
    if (i > 0) {
      result += " ";
    }
  }
  return result;
}
