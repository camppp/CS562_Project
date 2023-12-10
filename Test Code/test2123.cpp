#include <iostream>

enum class AtomicType {
  INTEGER,
  FLOAT,
  STRING
};

template<class T>
class AtomicValue {
 public:
  T value;
  AtomicType type;

  AtomicValue(T new_value, AtomicType new_type) : value(new_value), type(new_type) {}
};

int main() {
  // Example usage
  AtomicValue<int> int_value(10, AtomicType::INTEGER);
  AtomicValue<float> float_value(3.14f, AtomicType::FLOAT);
  AtomicValue<std::string> string_value("Hello", AtomicType::STRING);

  std::cout << "Integer value: " << int_value.value << std::endl;
  std::cout << "Float value: " << float_value.value << std::endl;
  std::cout << "String value: " << string_value.value << std::endl;

  return 0;
}
