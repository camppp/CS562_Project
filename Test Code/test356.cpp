#include <iostream>

class NetworkPort {
public:
    virtual int id() = 0;
    virtual std::string kind() = 0;
    virtual bool link() = 0;
    virtual int speed() = 0;
    virtual std::string duplex() = 0;
};

class CustomNetworkPort : public NetworkPort {
public:
    CustomNetworkPort(int id, std::string kind, bool link, int speed, std::string duplex)
        : id_(id), kind_(kind), link_(link), speed_(speed), duplex_(duplex) {}

    int id() override { return id_; }
    std::string kind() override { return kind_; }
    bool link() override { return link_; }
    int speed() override { return speed_; }
    std::string duplex() override { return duplex_; }

    void printDetails() {
        std::cout << "ID: " << id_ << std::endl;
        std::cout << "Kind: " << kind_ << std::endl;
        std::cout << "Link: " << link_ << std::endl;
        std::cout << "Speed: " << speed_ << std::endl;
        std::cout << "Duplex: " << duplex_ << std::endl;
    }

private:
    int id_;
    std::string kind_;
    bool link_;
    int speed_;
    std::string duplex_;
};

int main() {
    CustomNetworkPort port(1, "Ethernet", true, 1000, "Full");
    port.printDetails();
    return 0;
}
