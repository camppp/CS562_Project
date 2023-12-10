#include <iostream>

class PID {
private:
    double Kp, Ki, Kd;
    double p_error, i_error, d_error;

public:
    PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd), p_error(0), i_error(0), d_error(0) {}

    void UpdateError(double cte) {
        d_error = cte - p_error;  // Calculate the derivative error
        p_error = cte;  // Update the proportional error
        i_error += cte;  // Accumulate the integral error
    }

    double TotalError() {
        return -Kp * p_error - Ki * i_error - Kd * d_error;  // Calculate and return the total error
    }
};

int main() {
    // Example usage of the PID controller
    PID pid_controller(0.1, 0.01, 0.5);  // Initialize PID controller with coefficients
    double current_error = 0.05;  // Current error from the system
    pid_controller.UpdateError(current_error);  // Update the PID errors
    double control_output = pid_controller.TotalError();  // Calculate the control output
    std::cout << "Control Output: " << control_output << std::endl;
    return 0;
}
