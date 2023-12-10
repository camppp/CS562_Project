float computeSphereThickness(const float invmat[16], const float position[3], const float thicknessSquared) {
    const float tx = invmat[0] * position[0] + invmat[1] * position[1] + invmat[2] * position[2];
    const float ty = invmat[4] * position[0] + invmat[5] * position[1] + invmat[6] * position[2];
    const float tz = invmat[8] * position[0] + invmat[9] * position[1] + invmat[10] * position[2];
    return thicknessSquared / (tx*tx + ty*ty + tz*tz + IMP_MIN_DIVISOR);
}
