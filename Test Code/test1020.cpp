#include <iostream>
#include <string>

bool isARMArchitecture(const std::string& architecture) {
    return architecture.find("ARM") != std::string::npos;
}

int main() {
    std::string input;
    std::cout << "Enter the architecture name: ";
    std::cin >> input;
    if (isARMArchitecture(input)) {
        std::cout << "The architecture is ARM." << std::endl;
    } else {
        std::cout << "The architecture is not ARM." << std::endl;
    }
    return 0;
}
