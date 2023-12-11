#include <iostream>

class JoystickInput {
    public:
        JoystickInput(double axes[3]) {
            this->axes = axes;
        }

        double getLinearX() {
            return axes[0];
        }

    private:
        double axes[3];
};

int determineTargetGoal(JoystickInput joystickInput) {
    if (joystickInput.getLinearX() > 0.95) {
        return 1;
    } else if (joystickInput.getLinearX() < -0.95) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    double inputValues[3] = {0.8, -0.7, 0.5};
    JoystickInput joystick(inputValues);
    int userTargetGoal = determineTargetGoal(joystick);
    std::cout << "User target goal: " << userTargetGoal << std::endl;
    return 0;
}
