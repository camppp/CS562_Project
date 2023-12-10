#include <string>

namespace hersh {

std::string evaluate(const std::string& input) {
  // Remove leading and trailing whitespace
  std::string output = input;
  output.erase(output.begin(), std::find_if(output.begin(), output.end(), [](char c) {
    return !std::isspace(c);
  }));
  output.erase(std::find_if(output.rbegin(), output.rend(), [](char c) {
    return !std::isspace(c);
  }).base(), output.end());
  return output;
}

} // namespace hersh
