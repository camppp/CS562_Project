#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> findForbiddenTags(const std::vector<std::string>& iwyuPragmas) {
    std::vector<std::string> forbiddenTags;
    for (const auto& pragma : iwyuPragmas) {
        if (pragma.find("no_forward_declare") != std::string::npos) {
            std::string tag = pragma.substr(pragma.find("::") + 2);
            tag.erase(std::remove(tag.begin(), tag.end(), '"'), tag.end());
            forbiddenTags.push_back(tag);
        }
    }
    return forbiddenTags;
}

int main() {
    std::vector<std::string> iwyuPragmas = {
        "// IWYU pragma: no_forward_declare NewtonianEuler::Tags::Pressure",
        "// IWYU pragma: no_forward_declare NewtonianEuler::Tags::SpecificInternalEnergy",
        "// IWYU pragma: no_forward_declare NewtonianEuler::Tags::Velocity"
    };

    std::vector<std::string> forbiddenTags = findForbiddenTags(iwyuPragmas);
    for (const auto& tag : forbiddenTags) {
        std::cout << tag << std::endl;
    }

    return 0;
}
