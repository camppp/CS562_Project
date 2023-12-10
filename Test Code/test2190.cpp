class MeshIntersection {
public:
    // Method to load the 3D mesh data for both meshes
    void loadMeshData(const orion::Mesh& mesh1, const orion::Mesh& mesh2) {
        // Implement the loading of mesh data using the provided mesh objects
        // You can use the getter methods of the orion::Mesh class to access the mesh data
    }

    // Method to perform the intersection test and determine if the meshes intersect
    bool testIntersection() {
        // Implement the intersection test using the loaded mesh data
        // You can use the functionality provided by the assimp library for intersection tests
        // Return true if the meshes intersect, false otherwise
    }

    // Method to retrieve the intersection points and the intersecting triangles
    std::pair<std::vector<glm::vec3>, std::vector<std::pair<int, int>>> getIntersectionInfo() {
        // Implement the retrieval of intersection points and intersecting triangles
        // Return a pair containing the intersection points and the indices of the intersecting triangles
        // You can use the glm::vec3 class to represent the intersection points
    }
};
