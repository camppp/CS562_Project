#include <string>
#include <vector>

std::string join(const std::vector<std::string>& components) {
    std::string result;
    for (const auto& component : components) {
        result += component;
    }
    return result;
}
