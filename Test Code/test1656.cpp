#include <array>
#include <algorithm>

namespace sigma {
	enum class Bar {
		Zero,
		One,
		Two
	};
}

std::array<sigma::Bar, 3> invertValues(const std::array<sigma::Bar, 3>& input) {
    std::array<sigma::Bar, 3> result = input;
    std::reverse(result.begin(), result.end());
    return result;
}
