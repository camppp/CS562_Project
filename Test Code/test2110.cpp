namespace {

Optional<wchar_t> EncodeASCIIDigits(wchar_t digit1, wchar_t digit2) {
  if (!CBC_HighLevelEncoder::isDigit(digit1) ||
      !CBC_HighLevelEncoder::isDigit(digit2)) {
    return {};
  }
  return static_cast<wchar_t>((digit1 - 48) * 10 + (digit2 - 48) + 130);
}
