#include <iostream>
#include <string>

std::string formatText(const std::string& input) {
  std::string output;
  bool bold = false, italic = false, underline = false;

  for (char c : input) {
    if (c == '<') {
      if (input.substr(0, 3) == "<B>") {
        bold = true;
      } else if (input.substr(0, 3) == "<I>") {
        italic = true;
      } else if (input.substr(0, 3) == "<U>") {
        underline = true;
      }
    } else if (c == '>') {
      if (input.substr(0, 4) == "</B>") {
        bold = false;
      } else if (input.substr(0, 4) == "</I>") {
        italic = false;
      } else if (input.substr(0, 4) == "</U>") {
        underline = false;
      }
    } else {
      if (bold) {
        output += '\x1b[1m';
      }
      if (italic) {
        output += '\x1b[3m';
      }
      if (underline) {
        output += '\x1b[4m';
      }
      output += c;
      if (bold) {
        output += '\x1b[0m';
      }
      if (italic) {
        output += '\x1b[0m';
      }
      if (underline) {
        output += '\x1b[0m';
      }
    }
  }

  return output;
}

int main() {
  std::string input = "This is <B>bold</B> and <I>italic</I> text with <U>underline</U>.";
  std::string output = formatText(input);
  std::cout << output << std::endl;
  return 0;
}
