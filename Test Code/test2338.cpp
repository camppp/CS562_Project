#include <vector>
#include <string>
#include <utility>

std::pair<std::string, std::string> processText(const std::vector<std::pair<int, std::string>>& commands) {
  std::string origin, keyword;
  for (const auto& cmd : commands) {
    switch (cmd.first) {
      case 1:
        if (!origin.empty()) origin += " ";
        origin += cmd.second;
        break;
      case 2:
        if (!keyword.empty()) keyword += " ";
        keyword += cmd.second;
        break;
      case 3:
        origin.clear();
        break;
      case 4:
        keyword.clear();
        break;
      // additional cases can be handled here
    }
  }
  return std::make_pair(origin, keyword);
}
