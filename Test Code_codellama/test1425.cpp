#include <iostream>
#include <string>

// Base64 encoding function
std::string base64_encode(const std::string& input) {
  std::string output;
  for (int i = 0; i < input.size(); i += 3) {
    char a = input[i];
    char b = input[i + 1];
    char c = input[i + 2];
    output += (a >> 2) + (b >> 4) + (c >> 6);
    output += ((a & 0x3) << 4) + ((b & 0xf) << 2) + (c & 0x3f);
  }
  return output;
}

// Base64 decoding function
std::string base64_decode(const std::string& input) {
  std::string output;
  for (int i = 0; i < input.size(); i += 4) {
    char a = input[i];
    char b = input[i + 1];
    char c = input[i + 2];
    char d = input[i + 3];
    output += (a << 2) + (b >> 4) + (c >> 6);
    output += ((b & 0xf) << 4) + ((c & 0x3) << 2) + (d & 0x3f);
  }
  return output;
}

int main() {
  std::string input = "Hello, World!";
  std::string encoded = base64_encode(input);
  std::cout << "Encoded: " << encoded << std::endl;
  std::string decoded = base64_decode(encoded);
  std::cout << "Decoded: " << decoded << std::endl;
  return 0;
}
