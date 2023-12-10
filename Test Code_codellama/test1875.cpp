#include <string>
#include <algorithm>

std::string generateAcronym(const std::string& input) {
  std::string acronym;
  std::istringstream iss(input);
  std::string word;
  while (std::getline(iss, word, ' ')) {
    if (!word.empty()) {
      acronym += std::toupper(word[0]);
    }
  }
  return acronym;
}
