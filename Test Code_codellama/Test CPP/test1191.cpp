#include <ignition/math/Inertial.hh>

class Inertial {
 public:
  /// \brief Constructor from ignition::math::Inertial.
  /// \param[in] _inertial Ignition inertial object to copy.
  Inertial(const ignition::math::Inertiald &_inertial) {
    // Copy the inertial properties from the input object
    this->mass = _inertial.Mass();
    this->inertia = _inertial.Inertia();
  }

  /// \brief Copy constructor.
  /// \param[in] _inertial Inertial element to copy
  Inertial(const Inertial &_inertial) {
    // Copy the inertial properties from the input object
    this->mass = _inertial.mass;
    this->inertia = _inertial.inertia;
  }

  /// \brief Destructor.
  virtual ~Inertial() {
    // Release any allocated resources
  }

  /// \brief Get the mass of the inertial object.
  /// \return The mass of the inertial object.
  double Mass() const { return this->mass; }

  /// \brief Get the inertia of the inertial object.
  /// \return The inertia of the inertial object.
  ignition::math::Inertia Inertia() const { return this->inertia; }

 private:
  // Inertial properties
  double mass;
  ignition::math::Inertia inertia;
};
