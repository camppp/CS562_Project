std::pair<bool, int> chemotacticBehavior(double target_age, int last_visited, double window, double noise, bool on, double buffer, double& value) {
    bool updated = false;
    int new_last_visited = last_visited;

    // Check if the chemotactic behavior is active
    if (on) {
        // Check if the target is old enough to be considered for chemotaxis
        if (target_age >= window) {
            // Check if the last visit was within the window
            if (last_visited <= window) {
                // Check if the noise is within the acceptable range
                if (r_gen.get_rnum() <= noise) {
                    // Check if the buffer is present
                    if (buffer) {
                        // Reset the last visit time
                        new_last_visited = 0;
                    }
                    // Update the value
                    value = buffer;
                    updated = true;
                }
            }
        }
    }

    return std::make_pair(updated, new_last_visited);
}
