bool TotemTimingLocalTrack::containsHit(const Hit& hit, float tolerance) {
    // Calculate the distance between the hit and the track's position in 3D space
    float distance = sqrt(pow(hit.getX() - position.getX(), 2) +
                         pow(hit.getY() - position.getY(), 2) +
                         pow(hit.getZ() - position.getZ(), 2));

    // Calculate the combined uncertainty in position
    float combinedSigma = sqrt(pow(positionSigma.getX(), 2) +
                              pow(positionSigma.getY(), 2) +
                              pow(positionSigma.getZ(), 2));

    // Check if the distance is within the tolerance considering the combined uncertainty
    return distance <= tolerance + combinedSigma;
}
