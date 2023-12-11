#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <orion/Mesh.h>
#include <orion/Material.h>

namespace orion {

class MeshIntersection {
public:
    MeshIntersection(const Mesh& mesh1, const Mesh& mesh2);

    bool intersects() const;

    std::vector<IntersectionPoint> getIntersectionPoints() const;
    std::vector<IntersectingTriangle> getIntersectingTriangles() const;

private:
    const Mesh& mesh1_;
    const Mesh& mesh2_;
    std::vector<IntersectionPoint> intersection_points_;
    std::vector<IntersectingTriangle> intersecting_triangles_;

    void loadMeshData();
    void performIntersectionTest();
    void retrieveIntersectionPoints();
    void retrieveIntersectingTriangles();
};

MeshIntersection::MeshIntersection(const Mesh& mesh1, const Mesh& mesh2) : mesh1_(mesh1), mesh2_(mesh2) {
    loadMeshData();
    performIntersectionTest();
}

bool MeshIntersection::intersects() const {
    return !intersection_points_.empty();
}

std::vector<IntersectionPoint> MeshIntersection::getIntersectionPoints() const {
    return intersection_points_;
}

std::vector<IntersectingTriangle> MeshIntersection::getIntersectingTriangles() const {
    return intersecting_triangles_;
}

void MeshIntersection::loadMeshData() {
    // Load mesh data using Assimp
    const aiScene* scene1 = aiImportFile(mesh1_.getFilePath().c_str(), aiProcess_Triangulate | aiProcess_GenNormals);
    const aiScene* scene2 = aiImportFile(mesh2_.getFilePath().c_str(), aiProcess_Triangulate | aiProcess_GenNormals);

    // Check for errors
    if (!scene1 || !scene2) {
        throw std::runtime_error("Error loading mesh data");
    }

    // Get the mesh data
    const aiMesh* mesh1 = scene1->mMeshes[0];
    const aiMesh* mesh2 = scene2->mMeshes[0];

    // Check for errors
    if (!mesh1 || !mesh2) {
        throw std::runtime_error("Error loading mesh data");
    }

    // Get the material properties
    const aiMaterial* material1 = scene1->mMaterials[mesh1->mMaterialIndex];
    const aiMaterial* material2 = scene2->mMaterials[mesh2->mMaterialIndex];

    // Check for errors
    if (!material1 || !material2) {
        throw std::runtime_error("Error loading material properties");
    }

    // Store the mesh data and material properties
    mesh1_data_ = mesh1;
    mesh2_data_ = mesh2;
    material1_ = material1;
    material2_ = material2;
}

void MeshIntersection::performIntersectionTest() {
    // Perform the intersection test using Assimp
    const aiScene* scene1 = aiImportFile(mesh1_.getFilePath().c_str(), aiProcess_Triangulate | aiProcess_GenNormals);
    const aiScene* scene2 = aiImportFile(mesh2_.getFilePath().c_str(), aiProcess_Triangulate | aiProcess_GenNormals);

    // Check for errors
    if (!scene1 || !scene2) {
        throw std::runtime_error("Error performing intersection test");
    }

    // Get the mesh data
    const aiMesh* mesh1 = scene1->mMeshes[0];
    const aiMesh* mesh2 = scene2->mMeshes[0];

    // Check for errors
    if (!mesh1 || !mesh2) {
        throw std::runtime_error("Error performing intersection test");
    }

    // Perform the intersection test
    const aiIntersectonData* intersection_data = aiIntersect(mesh1, mesh2, nullptr, nullptr, nullptr);

    // Check for errors
    if (!intersection_data) {
        throw std::runtime_error("Error performing intersection test");
    }

    // Store the intersection data
    intersection_points_ = intersection_data->mIntersectionPoints;
    intersecting_triangles_ = intersection_data->mIntersectingTriangles;
}

void MeshIntersection::retrieveIntersectionPoints() {
    // Retrieve the intersection points
    for (const auto& intersection_point : intersection_points_) {
        // Get the position of the intersection point
        const aiVector3D& position = intersection_point.mPosition;

        // Get the normal of the intersection point
        const aiVector3D& normal = intersection_point.mNormal;

        // Get the texture coordinates of the intersection point
        const aiVector3D& texture_coordinates = intersection_point.mTextureCoordinates;

        // Store the intersection point
        intersection_points_.push_back(IntersectionPoint(position, normal, texture_coordinates));
    }
}

void MeshIntersection::retrieveIntersectingTriangles() {
    // Retrieve the intersecting triangles
    for (const auto& intersecting_triangle : intersecting_triangles_) {
        // Get the vertices of the intersecting triangle
        const aiVector3D& vertex1 = intersecting_triangle.mVertex1;
        const aiVector3D& vertex2 = intersecting_triangle.mVertex2;
        const aiVector3D& vertex3 = intersecting_triangle.mVertex3;

        // Get the normal of the intersecting triangle
        const aiVector3D& normal = intersecting_triangle.mNormal;

        // Get the texture coordinates of the intersecting triangle
        const aiVector3D& texture_coordinates1 = intersecting_triangle.mTextureCoordinates1;
        const aiVector3D& texture_coordinates2 = intersecting_triangle.mTextureCoordinates2;
        const aiVector3D& texture_coordinates3 = intersecting_triangle.mTextureCoordinates3;

        // Store the intersecting triangle
        intersecting_triangles_.push_back(IntersectingTriangle(vertex1, vertex2, vertex3, normal, texture_coordinates1, texture_coordinates2, texture_coordinates3));
    }
}

} // namespace orion
