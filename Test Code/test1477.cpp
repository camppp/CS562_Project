#include <iostream>
#include <string>

namespace nts {
    class BaseException {
        // Define the BaseException class if not already defined
    };

    class LinkErrorException : public BaseException {
    public:
        LinkErrorException(const char* message) : BaseException(), message_(message) {}
        LinkErrorException(const std::string& message) : BaseException(), message_(message) {}

        const char* what() const noexcept {
            return message_.c_str();
        }

    private:
        std::string message_;
    };
}

void simulateLinkError() {
    // Simulate a link error
    throw nts::LinkErrorException("Connection failed: Link error occurred");
}

int main() {
    try {
        simulateLinkError();
    } catch (const nts::LinkErrorException& e) {
        std::cerr << "Caught LinkErrorException: " << e.what() << std::endl;
    } catch (const nts::BaseException& e) {
        std::cerr << "Caught BaseException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught std::exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Caught unknown exception" << std::endl;
    }

    return 0;
}
