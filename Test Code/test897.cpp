void updateDeadReckoning(Filter& object_X_filter_xy, DeadReckoning& object_X_filter_dead_reckoning, double global_t) {
    // Update the dead reckoning algorithm
    const auto filter_estimate{ object_X_filter_xy.GetEstimate() };
    const auto glm_filter_estimate_pos{ glm::dvec3({ filter_estimate[0], filter_estimate[1], 0 }) };
    const auto glm_filter_estimate_acc{ glm::dvec3({ filter_estimate[4], filter_estimate[5], 0 }) };

    object_X_filter_dead_reckoning.SetSensorReading(glm_filter_estimate_pos, glm_filter_estimate_acc, global_t);
}
