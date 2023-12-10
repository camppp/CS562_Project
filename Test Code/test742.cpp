#include <string>
#include <vector>

// Define the StringList type
using StringList = std::vector<std::string>;

class NetworkConfig {
private:
  int m_workerPort;
  StringList m_search;
  bool m_clientSet;
  bool m_workerSet;

public:
  int workerPort() const { return this->m_workerPort; }
  const StringList& search() const { return this->m_search; }
  bool clientSet() const { return this->m_clientSet; }
  bool workerSet() const { return this->m_workerSet; }

  void convertHostPort(const std::string& hostport, std::string& host, int& port) {
    std::string::size_type pos = hostport.rfind(':');
    if (pos != std::string::npos) {
      host = hostport.substr(0, pos);
      if (pos + 1 < hostport.length()) {
        port = std::stoi(hostport.substr(pos + 1));
      }
    }
  }
};
