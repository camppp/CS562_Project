#include <iostream>
#include <string>
#include <vector>

class Channel {
public:
    Channel(const std::string& name, int channel_number, const std::string& anode_cathode_pair, int max_amplitude, int max_pulse_width)
        : name(name), channel_number(channel_number), anode_cathode_pair(anode_cathode_pair), max_amplitude(max_amplitude), max_pulse_width(max_pulse_width) {}

    const std::string& get_name() const { return name; }
    int get_channel_number() const { return channel_number; }
    const std::string& get_anode_cathode_pair() const { return anode_cathode_pair; }
    int get_max_amplitude() const { return max_amplitude; }
    int get_max_pulse_width() const { return max_pulse_width; }

private:
    std::string name;
    int channel_number;
    std::string anode_cathode_pair;
    int max_amplitude;
    int max_pulse_width;
};

std::vector<Channel> channels;

void create_channel(const std::string& name, int channel_number, const std::string& anode_cathode_pair, int max_amplitude, int max_pulse_width) {
    channels.push_back(Channel(name, channel_number, anode_cathode_pair, max_amplitude, max_pulse_width));
}

int main() {
    create_channel("muscle1", 1, "anode-cathode", 100, 1000);
    create_channel("muscle2", 2, "anode-cathode", 200, 2000);

    for (const auto& channel : channels) {
        std::cout << "Name: " << channel.get_name() << std::endl;
        std::cout << "Channel number: " << channel.get_channel_number() << std::endl;
        std::cout << "Anode-cathode pair: " << channel.get_anode_cathode_pair() << std::endl;
        std::cout << "Max amplitude: " << channel.get_max_amplitude() << std::endl;
        std::cout << "Max pulse width: " << channel.get_max_pulse_width() << std::endl;
    }

    return 0;
}
