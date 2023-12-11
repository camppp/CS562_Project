#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <operation> <number>" << std::endl;
    return 1;
  }

  std::string operation = argv[1];
  int number = std::stoi(argv[2]);

  if (operation == "square") {
    std::cout << number * number << std::endl;
  } else if (operation == "cube") {
    std::cout << number * number * number << std::endl;
  } else if (operation == "factorial") {
    int result = 1;
    for (int i = 1; i <= number; i++) {
      result *= i;
    }
    std::cout << result << std::endl;
  } else {
    std::cerr << "Invalid operation: " << operation << std::endl;
    return 1;
  }

  return 0;
}
