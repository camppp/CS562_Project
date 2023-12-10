#include "CompilerBase.hpp"
#include <memory>
#include <string>

class CCompiler : public CompilerBase {
public:
    void compile() override {
        // Implement compilation for C language
    }
};

class CppCompiler : public CompilerBase {
public:
    void compile() override {
        // Implement compilation for C++ language
    }
};

class JavaCompiler : public CompilerBase {
public:
    void compile() override {
        // Implement compilation for Java language
    }
};

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
            return nullptr; // Handle unsupported types or throw an exception
        }
    }
};
