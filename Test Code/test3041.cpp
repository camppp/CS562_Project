#include <iostream>
#include <cstdlib>

void printUsage() {
    std::cerr << "Usage: ./program <channel_id>" << std::endl;
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printUsage();
    } else {
        int thingSpeakChannelId = std::atoi(argv[1]);
        std::cout << "ThingSpeak write fields, Channel Id: " << thingSpeakChannelId << std::endl;
    }
    return 0;
}
