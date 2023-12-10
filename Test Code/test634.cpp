#include <iostream>

enum ErrorCode {
  kSuccess,
  kFileNotFound,
  kInvalidInput,
  kOutOfMemory
};

namespace Linux {
  std::string HandleError(ErrorCode error) {
    switch (error) {
      case kSuccess:
        return "Operation successful";
      case kFileNotFound:
        return "File not found";
      case kInvalidInput:
        return "Invalid input";
      case kOutOfMemory:
        return "Out of memory";
      default:
        return "Unknown error";
    }
  }
}

int main() {
  ErrorCode err = kFileNotFound;
  std::cout << Linux::HandleError(err) << std::endl;
  return 0;
}
