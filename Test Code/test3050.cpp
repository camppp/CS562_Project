#include <iostream>

namespace zap {

enum class link_type {
    static_,
    shared,
    automatic
};

class NetworkLink {
public:
    NetworkLink(link_type type) : type_(type) {}

    link_type get_type() const { return type_; }

    void set_type(link_type type) { type_ = type; }

private:
    link_type type_;
};

} // namespace zap

int main() {
    // Create instances of different link types
    zap::NetworkLink static_link(zap::link_type::static_);
    zap::NetworkLink shared_link(zap::link_type::shared);
    zap::NetworkLink automatic_link(zap::link_type::automatic);

    // Test the member functions
    std::cout << "Static link type: " << static_link.get_type() << std::endl;
    std::cout << "Shared link type: " << shared_link.get_type() << std::endl;
    std::cout << "Automatic link type: " << automatic_link.get_type() << std::endl;

    // Set new link types
    static_link.set_type(zap::link_type::shared);
    shared_link.set_type(zap::link_type::automatic);
    automatic_link.set_type(zap::link_type::static_);

    // Test the member functions again
    std::cout << "Static link type: " << static_link.get_type() << std::endl;
    std::cout << "Shared link type: " << shared_link.get_type() << std::endl;
    std::cout << "Automatic link type: " << automatic_link.get_type() << std::endl;

    return 0;
}
