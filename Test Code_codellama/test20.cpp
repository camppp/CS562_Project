class CommandExecutionException : public std::exception {
public:
    CommandExecutionException(const std::string& message) : message_(message) {}
    const char* what() const noexcept override { return message_.c_str(); }
private:
    std::string message_;
};
