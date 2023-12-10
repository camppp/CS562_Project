#include <iostream>
#include <fstream>
#include <string>

struct CpuFeatures {
  bool smp;
  bool isA53;
};

CpuFeatures ParseCpuInfo() {
  CpuFeatures features;
  std::ifstream cpuinfo("/proc/cpuinfo");
  if (cpuinfo.is_open()) {
    std::string line;
    while (std::getline(cpuinfo, line)) {
      if (line.find("smp") != std::string::npos) {
        features.smp = true;
      } else if (line.find("ARM A53") != std::string::npos) {
        features.isA53 = true;
      }
    }
  }
  return features;
}

int main() {
  CpuFeatures features = ParseCpuInfo();
  std::cout << "SMP: " << (features.smp ? "Yes" : "No") << std::endl;
  std::cout << "ARM A53: " << (features.isA53 ? "Yes" : "No") << std::endl;
  return 0;
}
