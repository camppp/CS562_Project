#include <exception>
#include <string>

class LibraryException : public std::exception {
public:
    LibraryException(const char* message) : std::exception(message) {}
};
