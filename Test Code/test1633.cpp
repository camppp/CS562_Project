python
class JoystickInput:
    def __init__(self, axes):
        self.axes = axes

def determineTargetGoal(joystick_input):
    if joystick_input.axes[svenzva_joy.linear_x] > 0.95:
        return 1
    elif joystick_input.axes[svenzva_joy.linear_x] < -0.95:
        return -1
    else:
        return 0

# Example usage
input_values = [0.8, -0.7, 0.5]  # Example joystick input values
joystick = JoystickInput(input_values)
user_target_goal = determineTargetGoal(joystick)
print(user_target_goal)  # Output: 0
