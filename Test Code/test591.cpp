#include <iostream>
#include <unordered_map>

class EncoderDecoder {
private:
    std::unordered_map<std::string, uint> rm;

public:
    void encode(uint value, const std::string& context) {
        // Perform encoding and store the result in the map rm at the specified context
        rm[context] = value;
    }

    uint decode(const std::string& context, uint r) {
        // Retrieve the encoded value from the map rm at the specified context and return the decoded value
        return rm[context] - r;
    }
};

int main() {
    EncoderDecoder encoderDecoder;
    encoderDecoder.encode(10, "context1");
    encoderDecoder.encode(20, "context2");

    std::cout << "Decoded value for context1: " << encoderDecoder.decode("context1", 5) << std::endl;
    std::cout << "Decoded value for context2: " << encoderDecoder.decode("context2", 8) << std::endl;

    return 0;
}
