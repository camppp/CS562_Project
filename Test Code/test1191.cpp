#include <ignition/math/Inertial.hh>

class Inertial {
private:
    ignition::math::Inertiald* inertialData;

public:
    /// \brief Constructor from ignition::math::Inertial.
    /// \param[in] _inertial Ignition inertial object to copy.
    // cppcheck-suppress noExplicitConstructor
    Inertial(const ignition::math::Inertiald &_inertial) {
        inertialData = new ignition::math::Inertiald(_inertial);
    }

    /// \brief Copy constructor.
    /// \param[in] _inertial Inertial element to copy
    Inertial(const Inertial &_inertial) {
        inertialData = new ignition::math::Inertiald(*(_inertial.inertialData));
    }

    /// \brief Destructor.
    virtual ~Inertial() {
        delete inertialData;
    }
};
