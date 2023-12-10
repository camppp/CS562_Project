#include <iostream>
#include <unordered_map>

class ConfigStep {
public:
    ConfigStep(const std::string& name) : name_(name) {}

    void addParent(const ConfigStep& parent) {
        parents_[parent.name_] = &parent;
    }

    std::string getErrorMessage() const {
        // Retrieve error message for the current step
        return "Error message for step '" + name_ + "'";
    }

    std::string getLogInformation() const {
        // Retrieve log information for the current step
        return "Log information for step '" + name_ + "'";
    }

private:
    std::string name_;
    std::unordered_map<std::string, const ConfigStep*> parents_;
};

int main() {
    ConfigStep step1("Step 1");
    ConfigStep step2("Step 2");
    ConfigStep step3("Step 3");

    step2.addParent(step1);
    step3.addParent(step1);
    step3.addParent(step2);

    std::cout << step1.getErrorMessage() << std::endl;
    std::cout << step2.getErrorMessage() << std::endl;
    std::cout << step3.getErrorMessage() << std::endl;

    std::cout << step1.getLogInformation() << std::endl;
    std::cout << step2.getLogInformation() << std::endl;
    std::cout << step3.getLogInformation() << std::endl;

    return 0;
}
