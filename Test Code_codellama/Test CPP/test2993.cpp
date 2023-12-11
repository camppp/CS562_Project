#include <iostream>
#include <cstdlib>

void customAbort(int errorCode, const std::string& errorMessage) {
    std::cerr << "Error: " << errorMessage << std::endl;
    std::abort();
}
