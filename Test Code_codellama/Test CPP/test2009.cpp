#include <iostream>

namespace MyNamespace {
  class MyClass {
  public:
    MyClass() {
      std::cout << "MyClass constructor called" << std::endl;
    }
  };
}

int main() {
  // Register the MyClass class within the MyNamespace namespace
  Qml::Register::Class<MyNamespace::MyClass>("MyNamespace", "MyClass");

  // Create an instance of the MyClass class
  MyNamespace::MyClass myClass;

  // Use the instance of the MyClass class
  std::cout << "MyClass instance created" << std::endl;

  return 0;
}
