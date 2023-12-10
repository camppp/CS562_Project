#include <optional>

namespace {

struct CBC_HighLevelEncoder {
  static bool isDigit(wchar_t c) {
    return c >= L'0' && c <= L'9';
  }
};

std::optional<wchar_t> EncodeASCIIDigits(wchar_t digit1, wchar_t digit2) {
  if (!CBC_HighLevelEncoder::isDigit(digit1) ||
      !CBC_HighLevelEncoder::isDigit(digit2)) {
    return {};  // Return empty optional if either digit is not a valid ASCII digit
  }
  // Convert ASCII digits to their numeric values and perform the encoding calculation
  wchar_t encodedChar = static_cast<wchar_t>((digit1 - L'0') * 10 + (digit2 - L'0') + 130);
  return encodedChar;
}

}  // namespace
