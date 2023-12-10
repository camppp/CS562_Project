double TorqueMap::interpolateTorque(double rpm) {
    auto it = dataPoints.lower_bound(rpm);
    if (it == dataPoints.begin()) {
        return it->second;
    }
    if (it == dataPoints.end()) {
        return (--it)->second;
    }
    auto prev = --it;
    double x0 = prev->first;
    double y0 = prev->second;
    double x1 = it->first;
    double y1 = it->second;
    return y0 + (y1 - y0) * (rpm - x0) / (x1 - x0);
}
