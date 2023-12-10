#include <vector>
#include <string>
#include <sstream>
#include "base.h"  // Assume base::IntToString is a function to convert int to string

std::vector<std::string> generateConfigurations(const std::vector<std::string>& ips, const std::vector<std::string>& hostnames, const std::vector<int>& ports) {
    std::vector<std::string> configurations;

    for (const auto& ip : ips) {
        for (const auto& hostname : hostnames) {
            for (const auto& port : ports) {
                std::stringstream configStream;
                configStream << "passport:" << ip << ":" << hostname << ":" << base::IntToString(port) << ":";
                configurations.push_back(configStream.str());
            }
        }
    }

    return configurations;
}
