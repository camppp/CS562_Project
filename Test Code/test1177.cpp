class ValidationSyntacticWarning {
public:
    ValidationSyntacticWarning(const std::string& code, const std::string& description, const std::string& reason, const std::string& module, const std::string& file, const std::string& mountPoint, const std::string& configFile, int lineNumber)
        : code_(code), description_(description), reason_(reason), module_(module), file_(file), mountPoint_(mountPoint), configFile_(configFile), lineNumber_(lineNumber) {}

    const std::string& getCode() const { return code_; }
    const std::string& getDescription() const { return description_; }
    const std::string& getReason() const { return reason_; }
    const std::string& getModule() const { return module_; }
    const std::string& getFile() const { return file_; }
    const std::string& getMountPoint() const { return mountPoint_; }
    const std::string& getConfigFile() const { return configFile_; }
    int getLineNumber() const { return lineNumber_; }

private:
    std::string code_;
    std::string description_;
    std::string reason_;
    std::string module_;
    std::string file_;
    std::string mountPoint_;
    std::string configFile_;
    int lineNumber_;
};

class ValidationSemanticWarning {
public:
    ValidationSemanticWarning(const std::string& code, const std::string& description, const std::string& reason, const std::string& module, const std::string& file, const std::string& mountPoint, const std::string& configFile, int lineNumber)
        : code_(code), description_(description), reason_(reason), module_(module), file_(file), mountPoint_(mountPoint), configFile_(configFile), lineNumber_(lineNumber) {}

    const std::string& getCode() const { return code_; }
    const std::string& getDescription() const { return description_; }
    const std::string& getReason() const { return reason_; }
    const std::string& getModule() const { return module_; }
    const std::string& getFile() const { return file_; }
    const std::string& getMountPoint() const { return mountPoint_; }
    const std::string& getConfigFile() const { return configFile_; }
    int getLineNumber() const { return lineNumber_; }

private:
    std::string code_;
    std::string description_;
    std::string reason_;
    std::string module_;
    std::string file_;
    std::string mountPoint_;
    std::string configFile_;
    int lineNumber_;
};
