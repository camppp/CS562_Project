void DnsProvisionerVubercool::provisionHostname(const string &hostname, const cb_t& onDone)
{
    int retries = 3; // Maximum number of retries
    provisionWithRetries(hostname, onDone, retries);
}

void DnsProvisionerVubercool::provisionWithRetries(const string &hostname, const cb_t& onDone, int retries)
{
    client_->Post("https://"s + config_.host + "/zone/" + hostname, [this, hostname, onDone, retries](Response& response) {
        if (response.success) {
            onDone(true); // Provisioning successful
        } else {
            if (retries > 0) {
                provisionWithRetries(hostname, onDone, retries - 1); // Retry provisioning
            } else {
                LOG_ERROR << "Failed to provision hostname (no more retries left): " << hostname;
                onDone(false); // Provisioning failed after all retries
            }
        }
    });
}

void DnsProvisionerVubercool::deleteHostname(const string &hostname, const cb_t& onDone)
{
    client_->Delete("https://"s + config_.host + "/zone/" + hostname, [onDone](Response& response) {
        onDone(response.success); // Call onDone with the success status of deletion
    });
}
