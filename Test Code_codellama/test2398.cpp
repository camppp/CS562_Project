#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

struct Configuration {
  int tcpPort;
  int wsPort;
  int threads;
  std::string logLevel;
  std::string file;
};

std::string serializeConfiguration(const Configuration& config) {
  std::ostringstream oss;
  oss << "{" << std::endl;
  oss << "  \"tcpPort\": " << config.tcpPort << "," << std::endl;
  oss << "  \"wsPort\": " << config.wsPort << "," << std::endl;
  oss << "  \"threads\": " << config.threads << "," << std::endl;
  oss << "  \"logLevel\": \"" << config.logLevel << "\"," << std::endl;
  oss << "  \"file\": \"" << config.file << "\"" << std::endl;
  oss << "}" << std::endl;
  return oss.str();
}

int main() {
  Configuration config = {8080, 9090, 4, "DEBUG", "config.json"};
  std::string json = serializeConfiguration(config);
  std::cout << json << std::endl;
  return 0;
}
