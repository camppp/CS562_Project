#include <iostream>

enum class net {
  OK,
  ERROR,
  TIMEOUT
};

net processNetworkRequests() {
  // Perform network requests
  // ...

  // Check for errors
  if (error_occurred) {
    return net::ERROR;
  }

  // Check for timeouts
  if (timeout_occurred) {
    return net::TIMEOUT;
  }

  // All requests successful, return OK
  return net::OK;
}
