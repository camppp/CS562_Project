#include <iostream>
#include <fstream>
#include <string>

bool checkLicense(const std::string& filePath) {
  std::ifstream file(filePath);
  if (!file.is_open()) {
    std::cerr << "Error: unable to open file " << filePath << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.find("Copyright 2021 OmniSci, Inc.") != std::string::npos) {
      // Found the copyright notice, now check for the license URL
      if (line.find("http://www.apache.org/licenses/LICENSE-2.0") != std::string::npos) {
        // Found the license URL, now check for the "Licensed under the Apache License, Version 2.0" line
        if (line.find("Licensed under the Apache License, Version 2.0") != std::string::npos) {
          // Found the license line, now check for the "WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied." line
          if (line.find("WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.") != std::string::npos) {
            // Found all the required lines, the license complies with the Apache License, Version 2.0
            return true;
          }
        }
      }
    }
  }

  // Did not find all the required lines, the license does not comply with the Apache License, Version 2.0
  return false;
}

int main() {
  std::string filePath = "example_license.txt";
  if (checkLicense(filePath)) {
    std::cout << "The license complies with the Apache License, Version 2.0" << std::endl;
  } else {
    std::cout << "The license does not comply with the Apache License, Version 2.0" << std::endl;
  }
  return 0;
}
