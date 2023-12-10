template <typename VDerived, typename FDerived>
auto face_normals(const Eigen::MatrixBase<VDerived>& V, const Eigen::MatrixBase<FDerived>& F) {
    // Compute the number of faces in the mesh
    int num_faces = F.rows();

    // Initialize the output matrix to store the normal vectors
    Eigen::Matrix<double, num_faces, 3> normals;

    // Loop over each face and compute the normal vector
    for (int i = 0; i < num_faces; i++) {
        // Get the vertices of the current face
        Eigen::Vector3d v0 = V.row(F(i, 0));
        Eigen::Vector3d v1 = V.row(F(i, 1));
        Eigen::Vector3d v2 = V.row(F(i, 2));

        // Compute the edge vectors for the current face
        Eigen::Vector3d e0 = v1 - v0;
        Eigen::Vector3d e1 = v2 - v1;

        // Compute the normal vector for the current face
        Eigen::Vector3d n = e0.cross(e1);

        // Normalize the normal vector to have unit length
        n.normalize();

        // Store the normal vector in the output matrix
        normals.row(i) = n;
    }

    return normals;
}
