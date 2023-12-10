#include <array>
#include <sigma/Bar.h>

std::array<sigma::Bar, 3> invertValues(const std::array<sigma::Bar, 3>& input) {
    std::array<sigma::Bar, 3> output;
    for (int i = 0; i < 3; i++) {
        output[i] = static_cast<sigma::Bar>(3 - i);
    }
    return output;
}
