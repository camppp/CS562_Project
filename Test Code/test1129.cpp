#include <iostream>
#include <string>
#include <sstream>

int longestNamespaceChainLength(const std::string& codeSnippet) {
    std::istringstream iss(codeSnippet);
    std::string line;
    int maxChainLength = 0;
    int currentChainLength = 0;

    while (std::getline(iss, line)) {
        int openBraces = 0;
        int i = 0;
        while (i < line.size() && line[i] == ' ') {
            i++;
        }
        while (i < line.size()) {
            if (line[i] == '{') {
                openBraces++;
            } else if (line[i] == '}') {
                openBraces--;
            } else if (line[i] == 'n' && line.substr(i, 9) == "namespace") {
                currentChainLength = openBraces + 1;
                if (currentChainLength > maxChainLength) {
                    maxChainLength = currentChainLength;
                }
            }
            i++;
        }
    }

    return maxChainLength;
}

int main() {
    std::string codeSnippet = R"(
namespace A {
namespace B {
namespace C {
}
}
}
namespace X {
namespace Y {
}
}
)";
    std::cout << longestNamespaceChainLength(codeSnippet) << std::endl;  // Output: 3
    return 0;
}
