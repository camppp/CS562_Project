#include <iostream>

// Definition of the NullOutStream class
class NullOutStream {
public:
    template <typename T>
    NullOutStream& operator<<(const T&) {
        return *this;  // No operation, effectively suppressing the log messages
    }
};

// Conditional setup for warning message logging
#ifdef ENS_PRINT_WARN
  static std::ostream& Warn = std::cerr;  // Redirect warning messages to standard error stream
#else
  static NullOutStream Warn;  // Suppress warning messages
#endif
