#include <iostream>
#include <string>
#include <vector>
#include <random>

std::vector<std::string> generateLicenseKey(const std::string& productCode, int numLicenses, int licenseLength) {
  std::vector<std::string> licenseKeys;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 25);

  for (int i = 0; i < numLicenses; i++) {
    std::string licenseKey = productCode + "-";
    for (int j = 0; j < licenseLength - productCode.length() - 1; j++) {
      licenseKey += dis(gen);
    }
    licenseKeys.push_back(licenseKey);
  }

  return licenseKeys;
}
