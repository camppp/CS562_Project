#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string temp;
    std::vector<char> jane_down, john_down;

    while (std::cin >> temp) {
        for (auto c : temp) {
            jane_down.push_back(c);
        }
        if (!(std::cin >> temp)) {
            break;
        }
        for (auto c : temp) {
            john_down.push_back(c);
        }

        if (jane_down.size() == john_down.size()) {
            if (jane_down < john_down) {
                std::cout << "Jane" << std::endl;
            } else {
                std::cout << "John" << std::endl;
            }
        } else {
            if (jane_down.size() > john_down.size()) {
                std::cout << "Jane" << std::endl;
            } else {
                std::cout << "John" << std::endl;
            }
        }

        jane_down.clear();
        john_down.clear();
    }

    return 0;
}
