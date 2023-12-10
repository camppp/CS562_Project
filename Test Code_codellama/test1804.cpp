#include <exception>

class CustomException : public std::exception {
public:
    CustomException(const std::string& message) : std::exception(message) {}

    ~CustomException() {
        // Perform custom cleanup operations here
    }
};
