#include <iostream>

namespace lp {
    template<typename T, int V>
    struct assoc_bit {
        static constexpr T value = V;
    };
}

int main() {
    using swpr_p30wp = lp::assoc_bit<swpr, 30>;
    using swpr_p29wp = lp::assoc_bit<swpr, 29>;
    using swpr_p28wp = lp::assoc_bit<swpr, 28>;
    using swpr_p27wp = lp::assoc_bit<swpr, 27>;

    std::cout << "swpr_p30wp: " << swpr_p30wp::value << std::endl;
    std::cout << "swpr_p29wp: " << swpr_p29wp::value << std::endl;
    std::cout << "swpr_p28wp: " << swpr_p28wp::value << std::endl;
    std::cout << "swpr_p27wp: " << swpr_p27wp::value << std::endl;

    return 0;
}
