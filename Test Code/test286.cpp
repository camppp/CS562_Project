#include <iostream>
#include <vector>
#include <string>

std::string processArrays(const std::vector<int>& fa, const std::vector<int>& fb) {
    bool js = false;
    std::string output;

    for (int i = 0; i < fa.size(); i++) {
        if (fa[i] || fb[i]) {
            output += std::to_string(i - 40000) + ' ';
            js = true;
        }
    }

    if (!js) {
        output = "nil\n";
    } else {
        output += "\n";
    }

    js = false;
    for (int i = 0; i < fa.size(); i++) {
        if (fa[i] && (!fb[i])) {
            // Perform additional operations if needed
        }
    }

    return output;
}
