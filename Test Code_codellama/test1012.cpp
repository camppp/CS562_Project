#include <iostream>
#include <string>
#include <unordered_map>

class VariableNotAssignedError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Variable not assigned";
    }
};

class VariableManager {
public:
    void assign_variable(const std::string& name, const std::string& value) {
        variables[name] = value;
    }

    std::string retrieve_variable(const std::string& name) {
        if (variables.find(name) == variables.end()) {
            throw VariableNotAssignedError();
        }
        return variables[name];
    }

    void modify_variable(const std::string& name, const std::string& new_value) {
        if (variables.find(name) == variables.end()) {
            throw VariableNotAssignedError();
        }
        variables[name] = new_value;
    }

private:
    std::unordered_map<std::string, std::string> variables;
};

int main() {
    VariableManager manager;
    manager.assign_variable("x", "10");
    std::cout << manager.retrieve_variable("x") << std::endl; // Output: 10
    manager.modify_variable("x", "20");
    std::cout << manager.retrieve_variable("x") << std::endl; // Output: 20
    std::cout << manager.retrieve_variable("y") << std::endl; // Output: VariableNotAssignedError
    return 0;
}
