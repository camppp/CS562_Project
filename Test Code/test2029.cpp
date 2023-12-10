#include <errno.h>

ssize_t processMessage(int errno, char* header) {
  ssize_t ret = errno ? -errno : errno;

  // Assuming pmsgHeader is a predefined structure or buffer
  size_t pmsgHeaderSize = sizeof(pmsgHeader);

  if (ret > (ssize_t)(sizeof(header) + pmsgHeaderSize)) {
    ret -= (sizeof(header) - pmsgHeaderSize);
  }

  return ret;
}
