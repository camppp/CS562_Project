#include <ipp/ipp.h>

bool LoadRangeOfInteger(const std::vector<uint8_t>& buf, ipp::RangeOfInteger* out) {
  // Check if the buffer size is correct
  if (buf.size() != 8) {
    return false;
  }

  // Check if the provided out pointer is valid
  if (out == nullptr) {
    return false;
  }

  // Load the range of integers from the buffer
  out->min = buf[0];
  out->max = buf[1];
  out->step = buf[2];

  // Check if the binary representation is correct
  if (out->min > out->max || out->step <= 0) {
    return false;
  }

  // Populate the ipp::RangeOfInteger object and return true
  return true;
}
