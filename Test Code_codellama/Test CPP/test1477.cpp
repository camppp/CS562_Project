#include <string>

namespace nts {

class LinkErrorException : public std::exception {
public:
    LinkErrorException(const char* message) : std::exception(message) {}
    LinkErrorException(const std::string& message) : std::exception(message) {}

    virtual const char* what() const noexcept override {
        return std::exception::what();
    }
};

} // namespace nts
