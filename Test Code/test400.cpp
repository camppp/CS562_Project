#include "robot_state_interface.hpp"
#include "actuator_command_interface.hpp"

namespace blmc_controllers
{
    class CentroidalPDController
    {
    public:
        CentroidalPDController(double kp, double kd)
            : kp_(kp), kd_(kd) {}

        void update(const RobotState& robot_state, ActuatorCommand& actuator_command)
        {
            // Obtain current center of mass position and velocity from robot state
            Eigen::Vector3d com_position = robot_state.getCenterOfMassPosition();
            Eigen::Vector3d com_velocity = robot_state.getCenterOfMassVelocity();

            // Calculate error between desired and current center of mass position and velocity
            Eigen::Vector3d com_position_error = desired_com_position_ - com_position;
            Eigen::Vector3d com_velocity_error = desired_com_velocity_ - com_velocity;

            // Compute control command using PD control law
            Eigen::Vector3d control_command = kp_ * com_position_error + kd_ * com_velocity_error;

            // Set the control command in the actuator command
            actuator_command.setControlCommand(control_command);
        }

        void setDesiredCenterOfMass(const Eigen::Vector3d& desired_position, const Eigen::Vector3d& desired_velocity)
        {
            desired_com_position_ = desired_position;
            desired_com_velocity_ = desired_velocity;
        }

    private:
        double kp_;  // Proportional gain
        double kd_;  // Derivative gain
        Eigen::Vector3d desired_com_position_;
        Eigen::Vector3d desired_com_velocity_;
    };
}  // namespace blmc_controllers
