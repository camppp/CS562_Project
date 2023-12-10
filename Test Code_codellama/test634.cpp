#include <string>

namespace Linux {

enum ErrorCode {
  kSuccess,
  kError1,
  kError2,
  kError3,
  kError4,
  kError5
};

std::string getErrorMessage(ErrorCode error) {
  switch (error) {
    case kSuccess:
      return "Operation completed successfully.";
    case kError1:
      return "Error 1 occurred.";
    case kError2:
      return "Error 2 occurred.";
    case kError3:
      return "Error 3 occurred.";
    case kError4:
      return "Error 4 occurred.";
    case kError5:
      return "Error 5 occurred.";
    default:
      return "Unknown error occurred.";
  }
}

} // namespace Linux
