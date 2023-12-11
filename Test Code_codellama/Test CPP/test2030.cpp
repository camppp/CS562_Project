#include <sstream>
#include <string>

bool compare_streams(const std::stringstream& stream1, const std::stringstream& stream2) {
  std::string str1, str2;
  stream1 >> str1;
  stream2 >> str2;
  return str1 == str2;
}
