#include <iostream>
#include <string>
#include <sstream>

struct LicenseInfo {
  std::string author;
  int year;
  std::string website;
  std::string software_name;
  std::string license_type;
};

LicenseInfo extractLicenseInfo(const std::string& license_text) {
  LicenseInfo info;
  std::stringstream ss(license_text);
  std::string line;
  while (std::getline(ss, line)) {
    if (line.find("http://") != std::string::npos) {
      info.website = line;
    } else if (line.find("-") != std::string::npos) {
      std::string license_type = line.substr(line.find("-") + 1);
      info.license_type = license_type;
    } else {
      std::string software_name = line.substr(0, line.find(" "));
      info.software_name = software_name;
      std::string author = line.substr(line.find(" ") + 1, line.find(" ") - 1);
      info.author = author;
      std::string year = line.substr(line.find(" ") + 1);
      info.year = std::stoi(year);
    }
  }
  return info;
}

int main() {
  std::string license_text = "tmxlite 2016\nhttp://trederia.blogspot.com\ntmxlite - Zlib license.";
  LicenseInfo info = extractLicenseInfo(license_text);
  std::cout << "Author: " << info.author << std::endl;
  std::cout << "Year: " << info.year << std::endl;
  std::cout << "Website: " << info.website << std::endl;
  std::cout << "Software name: " << info.software_name << std::endl;
  std::cout << "License type: " << info.license_type << std::endl;
  return 0;
}
