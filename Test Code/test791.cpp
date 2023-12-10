class ConfigStep {
public:
    ConfigStep(const std::string& name) : name_(name) {}

    void addParent(const ConfigStep& parent) {
        parents_.push_back(parent);
    }

    std::string getErrorMessage() const {
        return error_message_;
    }

    std::string getLogInformation() const {
        return log_information_;
    }

private:
    std::string name_;
    std::vector<ConfigStep> parents_;
    std::string error_message_;
    std::string log_information_;
};
