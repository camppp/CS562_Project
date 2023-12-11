class PacketSource_Raven : public KisPacketSource {
public:
    void ParseOptions(const std::vector<std::pair<std::string, std::string>>& options) override {
        // Check for the "device" option
        auto it = std::find_if(options.begin(), options.end(), [](const std::pair<std::string, std::string>& option) {
            return option.first == "device";
        });

        // If the "device" option is found, perform a specific action based on its value
        if (it != options.end()) {
            std::string device = it->second;
            if (device == "eth0") {
                // Do something specific for eth0
            } else if (device == "wlan0") {
                // Do something specific for wlan0
            } else {
                // Do something else
            }
        } else {
            // Proceed with the default behavior inherited from the base class
            KisPacketSource::ParseOptions(options);
        }
    }
};
