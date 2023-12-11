void validate_mps(const MPS& mps) {
    // Check if the required fields are present
    if (!mps.has_overlap()) {
        error_msg.append("Missing field: overlap\n");
    }
    if (!mps.has_norm()) {
        error_msg.append("Missing field: norm\n");
    }
    if (!mps.has_length()) {
        error_msg.append("Missing field: length\n");
    }
    if (!mps.has_iter()) {
        error_msg.append("Missing field: iter\n");
    }
    if (!mps.has_counter()) {
        error_msg.append("Missing field: counter\n");
    }
    if (!mps.has_time()) {
        error_msg.append("Missing field: time\n");
    }

    // Check for NaN values
    if (settings::debug) {
        if (std::isnan(mps.overlap())) {
            error_msg.append("NaN value found in field: overlap\n");
        }
        if (std::isnan(mps.norm())) {
            error_msg.append("NaN value found in field: norm\n");
        }
        if (std::isnan(mps.length())) {
            error_msg.append("NaN value found in field: length\n");
        }
        if (std::isnan(mps.iter())) {
            error_msg.append("NaN value found in field: iter\n");
        }
        if (std::isnan(mps.counter())) {
            error_msg.append("NaN value found in field: counter\n");
        }
        if (std::isnan(mps.time())) {
            error_msg.append("NaN value found in field: time\n");
        }
    }

    // Throw an error if any error messages are present
    if (!error_msg.empty()) {
        throw std::runtime_error(fmt::format("opt_mps error: {}", error_msg));
    }
}
