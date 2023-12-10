#include <memory>

// Base class for control messages
class ControlMessage {
  // Implementation details
};

// Implementation details for AntennaProfileControlMessage
struct AntennaProfileControlMessage::Implementation {
  AntennaProfileId id_;
  double dAntennaAzimuthDegrees_;
  double dAntennaElevationDegrees_;

  Implementation(AntennaProfileId id, double azimuth, double elevation)
    : id_(id), dAntennaAzimuthDegrees_(azimuth), dAntennaElevationDegrees_(elevation) {}
};

// AntennaProfileControlMessage class
class AntennaProfileControlMessage : public ControlMessage {
public:
  // Constructor
  AntennaProfileControlMessage(AntennaProfileId id, double dAntennaAzimuthDegrees, double dAntennaElevationDegrees)
    : ControlMessage{IDENTIFIER}, pImpl_{new Implementation{id, dAntennaAzimuthDegrees, dAntennaElevationDegrees}} {}

private:
  std::unique_ptr<Implementation> pImpl_;  // Private implementation
};
