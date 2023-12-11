class WalkingController {
public:
    // Constructor
    WalkingController(const ReferenceTrajectoryModule& refTrajModule,
                      const Eigen::Vector3d& initComPos)
        : refTrajModule_(refTrajModule),
          initComPos_(initComPos),
          maxVerticalForce_(10.0),
          endTime_(10.0),
          contactDimension_(2)
    {
        // Initialize the reference trajectory module
        refTrajModule_.initialize(initComPos_);
    }

    // Set the center of mass height
    void setComHeight(double comHeight) {
        comHeight_ = comHeight;
    }

    // Set the swing foot height
    void setSwingFootHeight(double swingFootHeight) {
        swingFootHeight_ = swingFootHeight;
    }

    // Get the center of mass height
    double getComHeight() const {
        return comHeight_;
    }

    // Get the swing foot height
    double getSwingFootHeight() const {
        return swingFootHeight_;
    }

    // Get the reference trajectory module
    const ReferenceTrajectoryModule& getRefTrajModule() const {
        return refTrajModule_;
    }

    // Get the maximum vertical force
    double getMaxVerticalForce() const {
        return maxVerticalForce_;
    }

    // Get the end time
    double getEndTime() const {
        return endTime_;
    }

    // Get the contact dimension
    int getContactDimension() const {
        return contactDimension_;
    }

    // Get the initial CoM position
    const Eigen::Vector3d& getInitComPos() const {
        return initComPos_;
    }

private:
    // Reference trajectory module
    ReferenceTrajectoryModule refTrajModule_;

    // Center of mass height
    double comHeight_;

    // Swing foot height
    double swingFootHeight_;

    // Maximum vertical force
    double maxVerticalForce_;

    // End time
    double endTime_;

    // Contact dimension
    int contactDimension_;

    // Initial CoM position
    Eigen::Vector3d initComPos_;
};
