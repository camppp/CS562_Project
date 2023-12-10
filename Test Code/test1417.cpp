CpuFeatures ParseCpuInfo() {
  CpuFeatures cpuFeatures;
  cpuFeatures.smp = false;
  cpuFeatures.isA53 = false;

  std::ifstream cpuInfoFile("/proc/cpuinfo");
  if (cpuInfoFile.is_open()) {
    std::string line;
    while (std::getline(cpuInfoFile, line)) {
      if (line.find("processor") != std::string::npos) {
        // Extract processor information if needed
      } else if (line.find("flags") != std::string::npos) {
        if (line.find("smp") != std::string::npos) {
          cpuFeatures.smp = true;
        }
        if (line.find("a53") != std::string::npos) {
          cpuFeatures.isA53 = true;
        }
      }
    }
    cpuInfoFile.close();
  } else {
    std::cerr << "Error: Unable to open /proc/cpuinfo" << std::endl;
  }

  return cpuFeatures;
}
