class DnsProvisionerVubercool {
private:
    Client client_;
    Config config_;

public:
    DnsProvisionerVubercool(Client client, Config config) : client_(client), config_(config) {}

    void provisionHostname(const std::string& hostname, const std::function<void(bool)>& onDone) {
        std::string url = "https://" + config_.host + "/zone/" + hostname;
        client_.Process(url, [this, hostname, onDone](const Response& response) {
            if (response.status == 200) {
                onDone(true);
            } else {
                LOG_ERROR("Failed to provision hostname " + hostname + ": " + response.status);
                onDone(false);
            }
        });
    }

    void deleteHostname(const std::string& hostname, const std::function<void(bool)>& onDone) {
        std::string url = "https://" + config_.host + "/zone/" + hostname;
        client_.Process(url, [this, hostname, onDone](const Response& response) {
            if (response.status == 200) {
                onDone(true);
            } else {
                LOG_ERROR("Failed to delete hostname " + hostname + ": " + response.status);
                onDone(false);
            }
        });
    }
};
