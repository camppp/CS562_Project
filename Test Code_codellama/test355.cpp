#include <iostream>

// Define the NullOutStream class
class NullOutStream {
public:
    NullOutStream() {}
    ~NullOutStream() {}

    // Overload the << operator to suppress log messages
    template<typename T>
    NullOutStream& operator<<(const T&) {
        return *this;
    }
};

// Define the ENS_PRINT_WARN macro
#ifdef ENS_PRINT_WARN
    #define Warn arma::get_cerr_stream()
#else
    #define Warn NullOutStream()
#endif

// Use the Warn stream to output warning messages
void warningMessage() {
    Warn << "This is a warning message" << std::endl;
}

int main() {
    // Test the logging behavior with ENS_PRINT_WARN defined
    #define ENS_PRINT_WARN
    warningMessage();

    // Test the logging behavior with ENS_PRINT_WARN undefined
    #undef ENS_PRINT_WARN
    warningMessage();

    return 0;
}
