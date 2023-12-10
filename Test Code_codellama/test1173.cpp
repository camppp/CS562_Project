#include <iostream>
#include <ranges>

namespace concepts {
    struct SizedRange {};
    struct OutputRange {};
    struct View {};
}

template <typename Range>
constexpr bool models(Range&& rng) {
    return std::ranges::view<Range>(rng);
}

int main() {
    // Example usage
    // ::models<concepts::SizedRange>(crng);
    // ::models<concepts::OutputRange>(crng);
    // ::models<concepts::View>(rng);
    
    return 0;
}
