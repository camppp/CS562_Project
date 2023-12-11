class PID {
public:
  // Constructor
  PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd) {}

  // Update the errors based on the current error
  void UpdateError(double cte) {
    p_error = cte;
    i_error += cte;
    d_error = cte - prev_cte;
    prev_cte = cte;
  }

  // Calculate and return the total error
  double TotalError() {
    return -Kp * p_error - Ki * i_error - Kd * d_error;
  }

private:
  // PID coefficients
  double Kp, Ki, Kd;

  // Proportional, integral, and derivative errors
  double p_error, i_error, d_error;

  // Previous cte
  double prev_cte;
};
