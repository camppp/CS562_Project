#include <string>
#include <cstring>
#include <sys/socket.h>
#include <sys/un.h>

void setupUnixSocketAddress(int family, const std::string& port, struct sockaddr_storage& sockaddr_) {
    struct sockaddr_un addr;
    addr.sun_family = family;
    memset(addr.sun_path, 0, sizeof(addr.sun_path)); // Clear the sun_path buffer
    strncpy(addr.sun_path, port.c_str(), sizeof(addr.sun_path) - 1); // Copy port to sun_path with proper null-termination

    // Copy the initialized sockaddr_un structure to the sockaddr_storage structure
    memmove(&sockaddr_, (struct sockaddr_storage *)&addr, sizeof(addr));
}
