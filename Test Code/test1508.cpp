#include <iostream>
#include <string>
#include "cxxopts.hpp"

int main(int argc, char* argv[]) {
    cxxopts::Options options("ccoold", "CCool daemon");
    options.add_options()
        ("h,help", "Show usage")
        ("i,interface", "Interface to use", cxxopts::value<std::string>()->default_value("usb"))
        ("n,no-daemon", "Do not run daemonized")
        ("s,socket", "Use specified socket", cxxopts::value<std::string>()->default_value("/var/run/ccool/ccoold.sock"))
        ("v,verbose", "Verbose logging messages");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return 0;
    }

    std::string interface = result["interface"].as<std::string>();
    bool runAsDaemon = !result.count("no-daemon");
    std::string socket = result["socket"].as<std::string>();
    bool verbose = result.count("verbose");

    // Use the parsed options as needed
    std::cout << "Interface: " << interface << std::endl;
    std::cout << "Run as daemon: " << (runAsDaemon ? "Yes" : "No") << std::endl;
    std::cout << "Socket: " << socket << std::endl;
    std::cout << "Verbose logging: " << (verbose ? "Enabled" : "Disabled") << std::endl;

    // Additional logic based on the parsed options can be implemented here

    return 0;
}
