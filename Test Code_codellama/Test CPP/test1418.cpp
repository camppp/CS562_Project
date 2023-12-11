#include <iostream>
#include <string>

void reverseString(std::string& s) {
  std::string reversedString;
  for (int i = s.length() - 1; i >= 0; i--) {
    reversedString += s[i];
  }
  s = reversedString;
}

int main(int argc, char* argv[]) {
  std::string s = "foobar";
  reverseString(s);
  std::cout << s << std::endl;
  return 0;
}
