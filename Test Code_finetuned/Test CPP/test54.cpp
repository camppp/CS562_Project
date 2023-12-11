#include <memory>

// Forward declaration of ControlMessage
class ControlMessage;

// Private implementation of AntennaProfileControlMessage
class AntennaProfileControlMessageImpl {
public:
    AntennaProfileControlMessageImpl(int id, double azimuth, double elevation)
        : id_(id), azimuth_(azimuth), elevation_(elevation) {}

    int id_;
    double azimuth_;
    double elevation_;
};

// AntennaProfileControlMessage class
class AntennaProfileControlMessage : public ControlMessage {
public:
    // Constructor
    AntennaProfileControlMessage(int id, double azimuth, double elevation)
        : ControlMessage(MessageType::ANTENNA_PROFILE_CONTROL),
          pImpl_(std::make_unique<AntennaProfileControlMessageImpl>(id, azimuth, elevation)) {}

    // Getters
    int getId() const { return pImpl_->id_; }
    double getAzimuth() const { return pImpl_->azimuth_; }
    double getElevation() const { return pImpl_->elevation_; }

private:
    std::unique_ptr<AntennaProfileControlMessageImpl> pImpl_;
};