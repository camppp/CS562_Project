#include <iostream>
#include <string>

namespace tensorflow {
namespace {

constexpr char kBaseApiDef[] =
    "tensorflow/core/api_def/base_api/*.pbtxt";
constexpr char kPythonApiDef[] =
    "tensorflow/core/api_def/python_api/*.pbtxt";
constexpr bool kUseApiDef = false;

std::string processFilePath(const std::string& fileName) {
  if (kUseApiDef) {
    return std::string(kPythonApiDef).replace(kPythonApiDef.find("*"), 1, fileName);
  } else {
    return std::string(kBaseApiDef).replace(kBaseApiDef.find("*"), 1, fileName);
  }
}

}  // namespace
}  // namespace tensorflow

int main() {
  std::string fileName = "example.pbtxt";
  std::cout << "Processed file path: " << tensorflow::processFilePath(fileName) << std::endl;
  return 0;
}
