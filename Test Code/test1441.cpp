#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
  // Check if the user provided any command-line options
  if (argc == 1) {
    std::cout << "No command-line options provided. Exiting." << std::endl;
    return 0;
  }

  // Process each command-line option
  for (int i = 1; i < argc; i++) {
    std::string option = argv[i];

    // Handle the 'c' option
    if (option == "-c") {
      // Check if the user provided an argument for the 'c' option
      if (i + 1 >= argc) {
        std::cout << "No argument provided for the 'c' option. Exiting." << std::endl;
        return 0;
      }

      // Process the argument for the 'c' option
      std::string argument = argv[i + 1];
      // ...

      // Handle the 'r' option
    } else if (option == "-r") {
      // Check if the user provided an argument for the 'r' option
      if (i + 1 >= argc) {
        std::cout << "No argument provided for the 'r' option. Exiting." << std::endl;
        return 0;
      }

      // Process the argument for the 'r' option
      std::string argument = argv[i + 1];
      // ...
    }
  }

  return 0;
}
