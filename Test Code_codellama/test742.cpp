#include <string>
#include <vector>

class NetworkConfig {
public:
    NetworkConfig() : m_workerPort(0), m_search(), m_clientSet(false), m_workerSet(false) {}

    int workerPort() const { return m_workerPort; }
    const StringList& search() const { return m_search; }
    bool clientSet() const { return m_clientSet; }
    bool workerSet() const { return m_workerSet; }

    void convertHostPort(const std::string& hostport, std::string& host, int& port) {
        size_t colon_pos = hostport.find(':');
        if (colon_pos != std::string::npos) {
            host = hostport.substr(0, colon_pos);
            port = std::stoi(hostport.substr(colon_pos + 1));
        } else {
            host = hostport;
            port = 0;
        }
    }

private:
    int m_workerPort;
    StringList m_search;
    bool m_clientSet;
    bool m_workerSet;
};
