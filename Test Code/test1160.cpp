#include <utility>

std::pair<bool, int> chemotacticBehavior(double target_age, int last_visited, double window, double noise, bool on, double buffer, double& value) {
    // Chemotactic synapse lag is implemented here.
    auto thr = std::max((target_age - last_visited) / window, (double)0.0f);
    bool valueUpdated = false;

    if (on && r_gen.get_rnum() > thr && (noise == 0.0 || (noise != 1.0 && r_gen.get_rnum() > noise))) {
        value = buffer;
        valueUpdated = true;
    }

    if (buffer) {
        last_visited = 0;
    }

    return std::make_pair(valueUpdated, last_visited);
}
