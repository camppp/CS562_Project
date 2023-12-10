#include <iostream>

bool parse_args(int argc, char **argv) {
  if (argc < 4) {
    return false;
  } else if (argc == 4) {
    std::cout << "Processing 4 arguments" << std::endl;
    return true;
  } else if (argc > 4) {
    std::cout << "Processing more than 4 arguments" << std::endl;
    return true;
  } else if (argc == 5 && std::string(argv[4]) == "verbose") {
    std::cout << "Processing 5 arguments in verbose mode" << std::endl;
    return true;
  } else {
    std::cout << "Invalid arguments" << std::endl;
    return false;
  }
}

int main(int argc, char **argv) {
  if (parse_args(argc, argv)) {
    // Perform further processing based on the parsed arguments
  } else {
    // Handle the case where the arguments are invalid
  }
  return 0;
}
