void updateDeadReckoning(Filter& object_X_filter_xy, DeadReckoning& object_X_filter_dead_reckoning, double global_t) {
    // Get the filter estimate
    std::vector<double> estimate = object_X_filter_xy.GetEstimate();

    // Update the dead reckoning algorithm with the filter estimate
    object_X_filter_dead_reckoning.SetSensorReading(glm::dvec3(estimate[0], estimate[1], estimate[2]),
                                                    glm::dvec3(estimate[3], estimate[4], estimate[5]),
                                                    global_t);
}
