#include <iostream>
#include "linux_parser.h"

class Processor {
 public:
  float Utilization();
};

float Processor::Utilization() {
  long activeJiffies = LinuxParser::ActiveJiffies();
  long totalJiffies = LinuxParser::Jiffies();
  return (float)activeJiffies / totalJiffies;
}

int main() {
  Processor processor;
  float utilization = processor.Utilization();
  std::cout << "CPU utilization: " << utilization << std::endl;
  return 0;
}
