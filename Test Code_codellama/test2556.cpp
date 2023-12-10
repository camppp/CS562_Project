#include <cmath>

class TotemTimingLocalTrack {
public:
    TotemTimingLocalTrack(const math::XYZPoint& position, const math::XYZPoint& positionSigma, float time, float timeSigma)
        : position(position), positionSigma(positionSigma), time(time), timeSigma(timeSigma) {}

    bool containsHit(const Hit& hit, float tolerance) const {
        // Calculate the distance between the hit and the track position
        float dx = hit.position.x() - position.x();
        float dy = hit.position.y() - position.y();
        float dz = hit.position.z() - position.z();
        float distance = sqrt(dx * dx + dy * dy + dz * dz);

        // Check if the distance is within the tolerance
        if (distance <= tolerance) {
            return true;
        }

        // Calculate the distance between the hit and the track position with uncertainties
        float dxSigma = hit.position.x() - position.x() + hit.positionSigma.x() - positionSigma.x();
        float dySigma = hit.position.y() - position.y() + hit.positionSigma.y() - positionSigma.y();
        float dzSigma = hit.position.z() - position.z() + hit.positionSigma.z() - positionSigma.z();
        float distanceSigma = sqrt(dxSigma * dxSigma + dySigma * dySigma + dzSigma * dzSigma);

        // Check if the distance with uncertainties is within the tolerance
        if (distanceSigma <= tolerance) {
            return true;
        }

        return false;
    }

private:
    math::XYZPoint position;
    math::XYZPoint positionSigma;
    float time;
    float timeSigma;
};
