#include <string>
#include <unordered_set>

bool CheckPermutation(const std::string& s1, const std::string& s2) {
  std::unordered_set<char> chars;
  for (const char c : s1) {
    chars.insert(c);
  }
  for (const char c : s2) {
    if (chars.find(c) == chars.end()) {
      return false;
    }
  }
  return true;
}
