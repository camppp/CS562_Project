void computeKKTSystem(const vector<Robot>& robots, const GridInfo& gridInfo, const vector<double>& prev_q, const vector<double>& prev_v, const vector<double>& current_s, const vector<double>& next_s, Matrix& kkt_matrix, Vector& kkt_residual) {
  // Compute the KKT matrix and residual for each robot
  for (int i = 0; i < robots.size(); i++) {
    // Compute the Jacobian of the robot's dynamics
    Matrix J = computeJacobian(robots[i], gridInfo, prev_q, prev_v, current_s, next_s);

    // Compute the KKT matrix and residual for the robot
    kkt_matrix.block(i, i, J.rows(), J.cols()) = J;
    kkt_residual.segment(i, J.rows()) = J * current_s.segment(i, J.cols()) - next_s.segment(i, J.cols());
  }
}
