// tmb::Address
class Address {
public:
    Address(int recipientId) : recipientId_(recipientId) {}

    int getRecipientId() const { return recipientId_; }

private:
    int recipientId_;
};

// tmb::TaggedMessage
class TaggedMessage {
public:
    TaggedMessage(const std::string& payload, size_t size) : payload_(payload), size_(size) {}

    const std::string& getPayload() const { return payload_; }
    size_t getSize() const { return size_; }

private:
    std::string payload_;
    size_t size_;
};
