#include <stdexcept>
#include <fmt/core.h>
#include <cmath>

// Define the MPS data structure
struct MPS {
    bool overlap;
    bool norm;
    bool length;
    bool iter;
    bool counter;
    bool time;
    // Other fields and methods
};

namespace settings {
    constexpr bool debug = true;  // Debug flag
}

// Validation function for the MPS data structure
void validate_mps(const MPS& mps) {
    std::string error_msg;

    if(!mps.overlap)  error_msg.append("\t overlap \n");
    if(!mps.norm)     error_msg.append("\t norm    \n");
    if(!mps.length)   error_msg.append("\t length  \n");
    if(!mps.iter)     error_msg.append("\t iter    \n");
    if(!mps.counter)  error_msg.append("\t counter \n");
    if(!mps.time)     error_msg.append("\t time    \n");

    if constexpr (settings::debug) {
        // Check for NaN values if debug flag is enabled
        if(std::isnan(/* access the relevant field in mps */)) {
            throw std::runtime_error("opt_mps error: mps has nan's");
        }
    }

    if(!error_msg.empty()) {
        throw std::runtime_error(fmt::format("opt_mps error: Missing fields:\n{}", error_msg));
    }
}

int main() {
    // Example usage of the validate_mps function
    MPS sample_mps{true, true, false, true, false, true};
    try {
        validate_mps(sample_mps);
        // Validation successful
    } catch(const std::runtime_error& e) {
        // Handle the validation error
    }
    return 0;
}
