#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>

tf::Transform convertStateToTransformation(const double eta[3]) {
    tf::Transform transform;

    // Set the translation part of the transformation
    transform.setOrigin(tf::Vector3(eta[0], eta[1], 0));

    // Set the rotation part of the transformation
    tf::Quaternion q;
    q.setRPY(0, 0, eta[2]);
    transform.setRotation(q);

    return transform;
}

int main() {
    // Given vessel state
    double eta[3] = {1.0, 2.0, 1.57};  // x, y, yaw

    // Convert vessel state to transformation matrix
    tf::Transform vesselTransform = convertStateToTransformation(eta);

    // Output the transformation matrix
    std::cout << "Transformation Matrix:" << std::endl;
    std::cout << vesselTransform.getBasis().getRow(0).getX() << " " << vesselTransform.getBasis().getRow(0).getY() << " " << vesselTransform.getBasis().getRow(0).getZ() << " " << vesselTransform.getOrigin().getX() << std::endl;
    std::cout << vesselTransform.getBasis().getRow(1).getX() << " " << vesselTransform.getBasis().getRow(1).getY() << " " << vesselTransform.getBasis().getRow(1).getZ() << " " << vesselTransform.getOrigin().getY() << std::endl;
    std::cout << vesselTransform.getBasis().getRow(2).getX() << " " << vesselTransform.getBasis().getRow(2).getY() << " " << vesselTransform.getBasis().getRow(2).getZ() << " " << vesselTransform.getOrigin().getZ() << std::endl;
    std::cout << "0 0 0 1" << std::endl;

    return 0;
}
