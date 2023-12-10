#include <iostream>
#include <Eigen/Dense>

int main() {
    // Input rotation matrix R and translation vector t
    Eigen::Matrix3f R;
    R << 0.866, -0.5, 0,
         0.5, 0.866, 0,
         0, 0, 1;
    
    Eigen::Vector3f t(1, 2, 3);

    // Input set of 3D points
    Eigen::Matrix3Xf original_points(3, 4);
    original_points << 1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12;

    // Apply transformation to each 3D point
    Eigen::Matrix3Xf transformed_points(3, original_points.cols());
    for (int i = 0; i < original_points.cols(); i++) {
        Eigen::Vector3f original_point = original_points.col(i);
        Eigen::Vector3f transformed_point = R * original_point + t;
        transformed_points.col(i) = transformed_point;
    }

    // Output the matrix of transformed 3D points
    std::cout << "Transformed 3D points:\n" << transformed_points << std::endl;

    return 0;
}
