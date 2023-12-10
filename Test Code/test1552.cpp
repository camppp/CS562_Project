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
        assert(!hello.empty());  // Assertion 1
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

int main() {
    // Creating old_sd and new_sd objects
    ServiceDiscoveryEvent old_sd("example.com", 8080, "Hello, old!", -1, "Unknown");
    ServiceDiscoveryEvent new_sd("example.com", 8080, "Hello, new!", 10, "TypeA");

    // Assertions for old_sd
    assert(old_sd.hello().empty() == false);  // Assertion 1
    assert(old_sd.host() == "example.com");   // Assertion 2
    assert(old_sd.port() == 8080);             // Assertion 2
    assert(old_sd.round_trip_time() == -1);    // Assertion 3
    assert(old_sd.type() == "Unknown");        // Assertion 4

    // Assertions for new_sd
    assert(new_sd.hello().empty() == false);   // Assertion 1
    assert(new_sd.host() == "example.com");    // Assertion 2
    assert(new_sd.port() == 8080);              // Assertion 2
    assert(new_sd.round_trip_time() >= 0);     // Assertion 3
    assert(new_sd.type() == "TypeA");          // No direct assertion for type, as it's not explicitly checked in the original code snippet

    return 0;
}
