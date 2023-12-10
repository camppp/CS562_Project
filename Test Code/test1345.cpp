#include <iostream>

// Template metaprogramming to associate a bit with a value
template <typename Bit, int Value>
struct assoc_bit {
    using bit = Bit;
    static constexpr int value = Value;
};

// Demonstration of the usage of lp::assoc_bit
int main() {
    // Associating bits with their respective values
    using swpr_p30wp = assoc_bit<swpr, 30>;
    using swpr_p29wp = assoc_bit<swpr, 29>;
    using swpr_p28wp = assoc_bit<swpr, 28>;
    using swpr_p27wp = assoc_bit<swpr, 27>;

    // Output the associated values
    std::cout << "swpr_p30wp value: " << swpr_p30wp::value << std::endl;
    std::cout << "swpr_p29wp value: " << swpr_p29wp::value << std::endl;
    std::cout << "swpr_p28wp value: " << swpr_p28wp::value << std::endl;
    std::cout << "swpr_p27wp value: " << swpr_p27wp::value << std::endl;

    return 0;
}
