// INetEndpoint.h

#ifndef INETENDPOINT_H
#define INETENDPOINT_H

#include <string>

namespace network {
    class INetEndpoint {
    private:
        std::string address;
        int port;

    public:
        void setAddress(const std::string& addr) {
            address = addr;
        }

        void setPort(int p) {
            port = p;
        }

        std::string getAddress() const {
            return address;
        }

        int getPort() const {
            return port;
        }

        bool isValid() const {
            return !address.empty() && port > 0;
        }
    };
}

#endif // INETENDPOINT_H
