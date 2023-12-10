#include <iostream>
#include <vector>
#include <string>

enum AnodeCathodePair {
    AN_CA_1,
    AN_CA_2,
    AN_CA_3
};

enum ChannelNumber {
    CH_5 = 5,
    CH_6 = 6,
    CH_7 = 7
};

class Channel {
private:
    std::string name;
    int channel_number;
    AnodeCathodePair anode_cathode_pair;
    int max_amplitude;
    int max_pulse_width;

public:
    Channel(std::string name, int channel_number, AnodeCathodePair anode_cathode_pair, int max_amplitude, int max_pulse_width)
        : name(name), channel_number(channel_number), anode_cathode_pair(anode_cathode_pair), max_amplitude(max_amplitude), max_pulse_width(max_pulse_width) {}

    std::string get_name() {
        return name;
    }

    int get_channel_number() {
        return channel_number;
    }

    AnodeCathodePair get_anode_cathode_pair() {
        return anode_cathode_pair;
    }

    int get_max_amplitude() {
        return max_amplitude;
    }

    int get_max_pulse_width() {
        return max_pulse_width;
    }
};

void create_channel(std::vector<Channel>& channels, std::string name, int channel_number, AnodeCathodePair anode_cathode_pair, int max_amplitude, int max_pulse_width) {
    Channel new_channel(name, channel_number, anode_cathode_pair, max_amplitude, max_pulse_width);
    channels.push_back(new_channel);
}

int main() {
    std::vector<Channel> channels;

    // create new channel for Flexor Carpi Radialis (Channel 5, Anode Cathode Pair 1, max amp 100 mA, max pw 250 us)
    create_channel(channels, "Flexor Carpi Radialis", CH_5, AN_CA_1, 100, 250);

    // create new channel for Palmaris Longus (Channel 6, Anode Cathode Pair 2, max amp 100 mA, max pw 250 us)
    create_channel(channels, "Palmaris Longus", CH_6, AN_CA_2, 100, 250);

    // create new channel for Flexor Carpi Ulnaris (Channel 7, Anode Cathode Pair 3, max amp 100 mA, max pw 250 us)
    create_channel(channels, "Flexor Carpi Ulnaris", CH_7, AN_CA_3, 100, 250);

    // Accessing and printing details of the created channels
    for (const auto& channel : channels) {
        std::cout << "Name: " << channel.get_name() << ", Channel Number: " << channel.get_channel_number()
                  << ", Anode Cathode Pair: " << channel.get_anode_cathode_pair() << ", Max Amplitude: " << channel.get_max_amplitude()
                  << " mA, Max Pulse Width: " << channel.get_max_pulse_width() << " us" << std::endl;
    }

    return 0;
}
