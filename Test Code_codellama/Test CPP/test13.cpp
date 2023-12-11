std::pair<float, float> vectorToOrientation(const McVec3f& orientation) {
    float phiDeg = atan2(orientation.y, orientation.x) * 180.0 / M_PI;
    float thetaDeg = acos(orientation.z) * 180.0 / M_PI;
    return std::make_pair(phiDeg, thetaDeg);
}
