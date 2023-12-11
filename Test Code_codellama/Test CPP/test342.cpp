int num_faces(const Mesh& mesh) {
    int num_faces = 0;
    for (const auto& facet : mesh.facets) {
        num_faces += facet.size();
    }
    return num_faces;
}
