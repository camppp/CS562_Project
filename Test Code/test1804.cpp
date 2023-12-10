#include <exception>

class CustomException : public std::exception {
public:
    CustomException() noexcept {}  // Custom constructor if needed

    virtual ~CustomException() noexcept {
        // Custom cleanup operations specific to the exception class
    }
    
    // Add any additional member functions as needed
};
