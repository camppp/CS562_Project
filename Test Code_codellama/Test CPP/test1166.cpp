namespace flightlib {

class Command {
 public:
  // Constructors
  Command() {}
  Command(const Scalar t, const Scalar thrust, const Vector<3>& omega) {}
  Command(const Scalar t, const Vector<4>& thrusts) {}

  // Member variables
  Scalar t;
  Scalar collective_thrust;
  Vector<3> omega;
  Vector<4> thrusts;

  // Methods
  bool valid() const {
    // Check if the command is valid
    return true;
  }

  bool isSingleRotorThrusts() const {
    // Check if the command represents single rotor thrusts
    return thrusts.size() == 4;
  }
};

} // namespace flightlib
