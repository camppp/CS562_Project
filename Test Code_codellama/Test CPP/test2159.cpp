class ConnectionResult {
public:
    enum class ResultType {
        AssociationRejected,
        ConnectionFailed,
        ConnectionEstablished
    };

    ConnectionResult(ResultType type, const std::string& reason = "")
        : type_(type), reason_(reason) {}

    ResultType getType() const { return type_; }
    const std::string& getReason() const { return reason_; }

private:
    ResultType type_;
    std::string reason_;
};

// Example usage:
ConnectionResult result = ConnectionResult(ConnectionResult::ResultType::AssociationRejected, "Invalid association request");
