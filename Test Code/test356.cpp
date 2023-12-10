#include <iostream>
#include <string>

// Enumerations for link status, speed, and duplex mode
enum class link_status { up, down };
enum class link_speed { _10mbps, _100mbps, _1gbps, _10gbps };
enum class link_duplex { half, full };

// Base class for network port abstraction
class NetworkPort {
public:
    virtual std::string id() const = 0;
    virtual std::string kind() const = 0;
    virtual link_status link() const = 0;
    virtual link_speed speed() const = 0;
    virtual link_duplex duplex() const = 0;
};

// Derived class for custom network port
class CustomNetworkPort : public NetworkPort {
private:
    std::string m_id;
    std::string m_kind;
    link_status m_link;
    link_speed m_speed;
    link_duplex m_duplex;

public:
    CustomNetworkPort(const std::string& id, const std::string& kind, link_status link, link_speed speed, link_duplex duplex)
        : m_id(id), m_kind(kind), m_link(link), m_speed(speed), m_duplex(duplex) {}

    std::string id() const override { return m_id; }
    std::string kind() const override { return m_kind; }
    link_status link() const override { return m_link; }
    link_speed speed() const override { return m_speed; }
    link_duplex duplex() const override { return m_duplex; }

    void printDetails() const {
        std::cout << "ID: " << m_id << std::endl;
        std::cout << "Kind: " << m_kind << std::endl;
        std::cout << "Link: " << (m_link == link_status::up ? "up" : "down") << std::endl;
        std::cout << "Speed: ";
        switch (m_speed) {
            case link_speed::_10mbps:
                std::cout << "10 Mbps";
                break;
            case link_speed::_100mbps:
                std::cout << "100 Mbps";
                break;
            case link_speed::_1gbps:
                std::cout << "1 Gbps";
                break;
            case link_speed::_10gbps:
                std::cout << "10 Gbps";
                break;
        }
        std::cout << std::endl;
        std::cout << "Duplex: " << (m_duplex == link_duplex::half ? "half" : "full") << std::endl;
    }
};

int main() {
    // Example usage
    CustomNetworkPort port("eth0", "Ethernet", link_status::up, link_speed::_1gbps, link_duplex::full);
    port.printDetails();
    return 0;
}
