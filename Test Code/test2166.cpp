#include <Eigen/Dense>

class WalkingReferenceTrajectoryModule {
    // Define the WalkingReferenceTrajectoryModule class
    // ...
};

class WalkingController {
public:
    WalkingController(WalkingReferenceTrajectoryModule* trajectory_module, const Eigen::Vector3d& initial_com_position)
        : walking_reference_trajectory_module_(trajectory_module), ini_com_pos_(initial_com_position) {}

    void setCoMHeight(double val) {
        target_com_height_ = val;
    }

    void setSwingFootHeight(double val) {
        swing_height_ = val;
    }

protected:
    WalkingReferenceTrajectoryModule* walking_reference_trajectory_module_;
    double max_fz_;
    double end_time_;
    int dim_contact_;
    Eigen::Vector3d ini_com_pos_;

private:
    double target_com_height_;
    double swing_height_;
};
