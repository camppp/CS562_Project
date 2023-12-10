#include <iostream>
#include <string>

namespace ripple {
    std::string to_string(int id) {
        return std::to_string(id);
    }
}  // namespace ripple

int main() {
    int id = 123;
    std::string idString = ripple::to_string(id);
    std::cout << "String representation of id: " << idString << std::endl;
    return 0;
}
