#include <iostream>
#include <vector>
#include <string>

class MessageBuilder {
private:
  std::vector<std::string> decodingErrors;

public:
  bool reportDecodingError(const std::string& errorMessage) {
    decodingErrors.push_back(errorMessage);
    return !decodingErrors.empty(); // Return true if there are more errors to handle
  }
};

int main() {
  MessageBuilder builder;
  bool moreErrors = builder.reportDecodingError("Decoding error 1");
  std::cout << "More decoding errors to handle: " << std::boolalpha << moreErrors << std::endl;

  moreErrors = builder.reportDecodingError("Decoding error 2");
  std::cout << "More decoding errors to handle: " << std::boolalpha << moreErrors << std::endl;

  moreErrors = builder.reportDecodingError("Decoding error 3");
  std::cout << "More decoding errors to handle: " << std::boolalpha << moreErrors << std::endl;

  return 0;
}
