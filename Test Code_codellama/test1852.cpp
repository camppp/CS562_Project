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
