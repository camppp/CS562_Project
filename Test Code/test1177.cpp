#include <string>

class ValidationSyntacticWarning {
private:
    int code_;
    std::string description_;
    std::string reason_;
    std::string module_;
    std::string file_;
    std::string mountPoint_;
    std::string configFile_;
    int line_;

public:
    ValidationSyntacticWarning(int code, const std::string& description, const std::string& reason,
                               const std::string& module, const std::string& file, const std::string& mountPoint,
                               const std::string& configFile, int line)
        : code_(code), description_(description), reason_(reason), module_(module), file_(file),
          mountPoint_(mountPoint), configFile_(configFile), line_(line) {}

    int code() const { return code_; }
    std::string description() const { return description_; }
    std::string reason() const { return reason_; }
    std::string module() const { return module_; }
    std::string file() const { return file_; }
    std::string mountPoint() const { return mountPoint_; }
    std::string configFile() const { return configFile_; }
    int line() const { return line_; }
};

class ValidationSemanticWarning {
private:
    int code_;
    std::string description_;
    std::string reason_;
    std::string module_;
    std::string file_;
    std::string mountPoint_;
    std::string configFile_;
    int line_;

public:
    ValidationSemanticWarning(int code, const std::string& description, const std::string& reason,
                              const std::string& module, const std::string& file, const std::string& mountPoint,
                              const std::string& configFile, int line)
        : code_(code), description_(description), reason_(reason), module_(module), file_(file),
          mountPoint_(mountPoint), configFile_(configFile), line_(line) {}

    int code() const { return code_; }
    std::string description() const { return description_; }
    std::string reason() const { return reason_; }
    std::string module() const { return module_; }
    std::string file() const { return file_; }
    std::string mountPoint() const { return mountPoint_; }
    std::string configFile() const { return configFile_; }
    int line() const { return line_; }
};
