#include <iostream>
#include <unordered_map>
#include <functional>
#include <stdexcept>

class FunctionRegistry {
private:
    std::unordered_map<std::string, std::function<void()>> functionMap;

public:
    void registerFunction(const std::string& functionName, const std::function<void()>& functionPtr) {
        if (functionMap.find(functionName) != functionMap.end()) {
            throw std::invalid_argument("Function with name " + functionName + " is already registered");
        }
        functionMap[functionName] = functionPtr;
    }

    template<typename... Args>
    void invokeFunction(const std::string& functionName, Args&&... args) {
        if (functionMap.find(functionName) == functionMap.end()) {
            throw std::invalid_argument("Function with name " + functionName + " is not registered");
        }
        functionMap[functionName](std::forward<Args>(args)...);
    }
};

// Example usage
namespace Core {
    namespace Cryptography {
        void scReduce32() {
            std::cout << "Executing scReduce32 function" << std::endl;
        }

        void hashToScalar() {
            std::cout << "Executing hashToScalar function" << std::endl;
        }
    }
}

int main() {
    FunctionRegistry registry;
    registry.registerFunction("scReduce32", &Core::Cryptography::scReduce32);
    registry.registerFunction("hashToScalar", &Core::Cryptography::hashToScalar);

    registry.invokeFunction("scReduce32");
    registry.invokeFunction("hashToScalar");

    return 0;
}
