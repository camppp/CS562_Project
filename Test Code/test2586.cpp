#include <vector>
#include <iter/iter.h>

std::vector<bool> transform_data(const std::vector<bool>& input) {
  std::vector<bool> result;
  auto grouped = iter::groupby(input, [](bool b) { return b; });
  for (auto& group : grouped) {
    auto dropwhile_true = iter::dropwhile(group.second, [](bool b) { return !b; });
    for (auto& value : dropwhile_true) {
      result.push_back(value);
    }
  }
  return result;
}

int main() {
  std::vector<bool> input{false, false, true, true, false, true, true};
  std::vector<bool> result = transform_data(input);
  // Output the result or perform further operations
  return 0;
}
