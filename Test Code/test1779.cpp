#include <iostream>
#include <string>

std::string findNamespaceDeclaration(const std::string& code) {
    size_t pos = code.find("namespace");
    if (pos != std::string::npos) {
        size_t endPos = code.find("}", pos);
        if (endPos != std::string::npos) {
            size_t bracePos = code.rfind("{", pos);
            if (bracePos != std::string::npos) {
                return code.substr(bracePos, endPos - bracePos + 1);
            }
        }
    }
    return "";
}

int main() {
    std::string code = "};\n}\n}  // namespace chainer_compiler\n";
    std::cout << findNamespaceDeclaration(code) << std::endl;
    return 0;
}
