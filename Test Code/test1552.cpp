#include <string>
#include <cassert>

class ServiceDiscoveryEvent {
private:
    std::string host_;
    int port_;
    std::string hello_;
    int round_trip_time_;
    std::string type_;

public:
    ServiceDiscoveryEvent(const std::string& host, int port, const std::string& hello, int round_trip_time, const std::string& type)
        : host_(host), port_(port), hello_(hello), round_trip_time_(round_trip_time), type_(type) {
        assert(!hello.empty());
        assert(host == host_ && port == port_);
        assert(round_trip_time_ == -1 || round_trip_time >= 0);
        assert(type_ == "Unknown");
    }

    std::string host() {
        return host_;
    }

    int port() {
        return port_;
    }

    std::string hello() {
        return hello_;
    }

    int round_trip_time() {
        return round_trip_time_;
    }

    std::string type() {
        return type_;
    }
};
