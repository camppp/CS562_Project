#include <iostream>
#include <string>
#include <cassert>

class XMLIterPrinter {
private:
  bool theOpenStart;

public:
  XMLIterPrinter() : theOpenStart(true) {}

  void addStrAttribute(const char *name, const char *value) {
    assert(theOpenStart);
    std::cout << ' ' << name << "=\"" << value << "\"";
  }

  void addIntAttribute(const char *name, xs_integer value) {
    assert(theOpenStart);
    std::cout << ' ' << name << "=\"" << value << "\"";
  }

  void addDecAttribute(const char *name, double value) {
    assert(theOpenStart);
    std::cout << ' ' << name << "=\"" << value << "\"";
  }
};
