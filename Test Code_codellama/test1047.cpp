#include <cmath>

double CommsPacket::DistanceTo(const CommsPacket& other) const {
  return std::sqrt(std::pow(this->position.X() - other.position.X(), 2) +
                   std::pow(this->position.Y() - other.position.Y(), 2) +
                   std::pow(this->position.Z() - other.position.Z(), 2));
}
