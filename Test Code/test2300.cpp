#include <iostream>
#include <string>
#include <cstdlib>

namespace faas {
    void GatewayMain(int argc, char* argv[]) {
        int port = 0;
        bool helpRequested = false;

        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if (arg == "-p" || arg == "--port") {
                if (i + 1 < argc) {
                    port = std::atoi(argv[i + 1]);
                    if (port <= 0) {
                        std::cerr << "Error: Invalid port number" << std::endl;
                        return;
                    }
                    ++i;  // Skip the next argument as it has been processed
                } else {
                    std::cerr << "Error: Port number is missing" << std::endl;
                    return;
                }
            } else if (arg == "-h" || arg == "--help") {
                helpRequested = true;
            } else {
                std::cerr << "Error: Unknown option '" << arg << "'" << std::endl;
                return;
            }
        }

        if (helpRequested) {
            std::cout << "Usage: gateway_app [-p <port> | --port <port>] [-h | --help]" << std::endl;
            return;
        }

        if (port == 0) {
            std::cerr << "Error: Port number is required" << std::endl;
            return;
        }

        // Start the server with the specified port
        std::cout << "Starting server on port " << port << std::endl;
        // Add server initialization and execution logic here
    }
}

int main(int argc, char* argv[]) {
    faas::GatewayMain(argc, argv);
    return 0;
}
