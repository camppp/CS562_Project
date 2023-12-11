#include <iostream>

void _FATALERROR(const char* message) {
    std::cerr << "Fatal error: " << message << std::endl;
    std::exit(1);
}

bool RegisterMessagingInterface() {
    // Install hooks for the messaging interface
    if (!Hooks::InstallHooks()) {
        _FATALERROR("Failed to install hooks for messaging interface");
        return false;
    }

    // Register the messaging interface
    if (!MessagingInterface::Register()) {
        _FATALERROR("Failed to register messaging interface");
        return false;
    }

    return true;
}
