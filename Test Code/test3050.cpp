#include <iostream>

namespace zap {

enum class link_type
{
    static_,
    shared_,
    auto_
};

class NetworkLink {
private:
    link_type type;

public:
    NetworkLink(link_type linkType) : type(linkType) {}

    link_type getLinkType() const {
        return type;
    }

    void setLinkType(link_type newType) {
        type = newType;
    }
};

} // namespace zap

int main() {
    using namespace zap;

    // Create instances of NetworkLink with different link types
    NetworkLink staticLink(link_type::static_);
    NetworkLink sharedLink(link_type::shared_);
    NetworkLink autoLink(link_type::auto_);

    // Test the member functions
    std::cout << "Initial link types:" << std::endl;
    std::cout << "Static link type: " << static_cast<int>(staticLink.getLinkType()) << std::endl;
    std::cout << "Shared link type: " << static_cast<int>(sharedLink.getLinkType()) << std::endl;
    std::cout << "Auto link type: " << static_cast<int>(autoLink.getLinkType()) << std::endl;

    // Change the link types and test again
    staticLink.setLinkType(link_type::auto_);
    sharedLink.setLinkType(link_type::static_);
    autoLink.setLinkType(link_type::shared_);

    std::cout << "\nUpdated link types:" << std::endl;
    std::cout << "Static link type: " << static_cast<int>(staticLink.getLinkType()) << std::endl;
    std::cout << "Shared link type: " << static_cast<int>(sharedLink.getLinkType()) << std::endl;
    std::cout << "Auto link type: " << static_cast<int>(autoLink.getLinkType()) << std::endl;

    return 0;
}
