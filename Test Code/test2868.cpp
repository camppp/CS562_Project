#include <iostream>
#include <exception>

class copy_not_implemented : public std::exception {
public:
  const char *what() const throw() { return "Masolas nincs implementalva!"; }
};

int main() {
  try {
    throw copy_not_implemented();
  } catch (const std::exception& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }
  return 0;
}
