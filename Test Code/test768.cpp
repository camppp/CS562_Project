#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> generateConfigurations(const std::vector<std::string>& ips, const std::vector<std::string>& hostnames, const std::vector<int>& ports) {
    std::vector<std::string> configurations;

    for (const auto& ip : ips) {
        for (const auto& hostname : hostnames) {
            for (const auto& port : ports) {
                configurations.push_back("passport:" + ip + ":" + hostname + ":" + std::to_string(port) + ":");
            }
        }
    }

    return configurations;
}
