#include <iostream>
#include <string>

class AntennaProfileControlMessage : public ControlMessage {
public:
    AntennaProfileControlMessage(int antennaProfileId, double azimuthAngle, double elevationAngle) {
        pImpl_ = new AntennaProfileControlMessageImpl(antennaProfileId, azimuthAngle, elevationAngle);
    }

    ~AntennaProfileControlMessage() {
        delete pImpl_;
    }

    int getAntennaProfileId() const {
        return pImpl_->getAntennaProfileId();
    }

    double getAzimuthAngle() const {
        return pImpl_->getAzimuthAngle();
    }

    double getElevationAngle() const {
        return pImpl_->getElevationAngle();
    }

private:
    class AntennaProfileControlMessageImpl {
    public:
        AntennaProfileControlMessageImpl(int antennaProfileId, double azimuthAngle, double elevationAngle) {
            this->antennaProfileId = antennaProfileId;
            this->azimuthAngle = azimuthAngle;
            this->elevationAngle = elevationAngle;
        }

        int getAntennaProfileId() const {
            return antennaProfileId;
        }

        double getAzimuthAngle() const {
            return azimuthAngle;
        }

        double getElevationAngle() const {
            return elevationAngle;
        }

    private:
        int antennaProfileId;
        double azimuthAngle;
        double elevationAngle;
    };

    AntennaProfileControlMessageImpl* pImpl_;
};
