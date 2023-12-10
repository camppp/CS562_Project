class MessageBuilder {
public:
  bool reportDecodingError(const std::string& errorMessage) {
    decodingErrors_.push_back(errorMessage);
    return !decodingErrors_.empty();
  }

private:
  std::vector<std::string> decodingErrors_;
};
