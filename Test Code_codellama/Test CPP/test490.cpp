#include <iostream>
#include "base/strings/string_util.h"

int main() {
  std::string input;
  std::getline(std::cin, input);

  // Convert the input string to lowercase
  std::string lowercase = base::strings::ToLower(input);

  // Remove any leading or trailing whitespace from the lowercase string
  std::string trimmed = base::strings::Trim(lowercase);

  // Split the resulting string into individual words based on whitespace
  std::vector<std::string> words = base::strings::Split(trimmed, " ");

  // Print each word on a new line
  for (const std::string& word : words) {
    std::cout << word << std::endl;
  }

  return 0;
}
