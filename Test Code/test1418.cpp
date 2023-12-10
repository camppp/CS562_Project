#include <iostream>
#include <string>

void reverseString(std::string& s) {
  int left = 0;
  int right = s.length() - 1;
  while (left < right) {
    std::swap(s[left], s[right]);
    left++;
    right--;
  }
}

int main(int argc, char* argv[]) {
  std::string s = "foobar";
  reverseString(s);
  std::cout << s << std::endl;
  return 0;
}
