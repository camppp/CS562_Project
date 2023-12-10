#include <iostream>
#include <cstdlib>

void customAbort(int errorCode, const std::string& errorMessage) {
    std::cerr << errorMessage << std::endl;
    std::abort();
}

int main() {
    // Example usage of customAbort
    customAbort(123, "Custom abort triggered: Critical error encountered");

    // The program will terminate after printing the error message
    std::cout << "This line will not be reached due to customAbort" << std::endl;

    return 0;
}
