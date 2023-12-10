#include <sstream>
#include <iomanip>

std::string serializeConfiguration(const Configuration& config) {
  std::ostringstream ss;
  ss << R"({"tcpPort": )" << config.tcpPort <<
    R"(, "wsPort": )" << config.wsPort <<
    R"(, "threads": )" << config.threads <<
    R"(, "logLevel": ")" << config.logLevel <<
    R"(", "file": )" << std::quoted(config.file) <<
    '}';
  return ss.str();
}
