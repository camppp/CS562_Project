double DistanceTo(const CommsPacket& other) const {
  const ignition::math::Vector3d& otherPosition = other.Position();
  const ignition::math::Vector3d& thisPosition = this->position;

  double distance = std::sqrt(
    std::pow(otherPosition.X() - thisPosition.X(), 2) +
    std::pow(otherPosition.Y() - thisPosition.Y(), 2) +
    std::pow(otherPosition.Z() - thisPosition.Z(), 2)
  );

  return distance;
}
