#include <iostream>

class IntegerPolyhedron {
public:
  void print(raw_ostream &os) const {
    // Implementation not shown
  }
};

class Output {
public:
  void print(raw_ostream &os) const {
    // Implementation not shown
  }
};

class MultiAffineFunction {
private:
  IntegerPolyhedron domain;
  Output output;

public:
  void print(raw_ostream &os) const {
    os << "Domain:";
    domain.print(os);
    os << "Output:\n";
    output.print(os);
    os << "\n";
  }
};

int main() {
  MultiAffineFunction function;
  // Assume domain and output are properly initialized
  function.print(std::cout);
  return 0;
}
