#include "CompilerBase.hpp"
#include <memory>
#include <string>

class CompilerFactory {
public:
    std::unique_ptr<CompilerBase> createCompiler(const std::string& type) {
        if (type == "C") {
            return std::make_unique<CCompiler>();
        } else if (type == "C++") {
            return std::make_unique<CppCompiler>();
        } else if (type == "Java") {
            return std::make_unique<JavaCompiler>();
        } else {
            throw std::invalid_argument("Invalid compiler type: " + type);
        }
    }
};
