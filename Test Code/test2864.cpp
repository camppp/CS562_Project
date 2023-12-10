void MeshViewer::updateMesh()
{
    // Compute face normals for each face in the mesh
    for (const auto& face : m_mesh.faces()) {
        Vector3f v0 = m_mesh.vertices()[face[0]];
        Vector3f v1 = m_mesh.vertices()[face[1]];
        Vector3f v2 = m_mesh.vertices()[face[2]];

        Vector3f edge1 = v1 - v0;
        Vector3f edge2 = v2 - v0;
        Vector3f faceNormal = cross(edge1, edge2).normalized();

        m_mesh.setFaceNormal(face, faceNormal);
    }

    // Compute vertex normals by averaging adjacent face normals for each vertex
    for (size_t vertexIdx = 0; vertexIdx < m_mesh.vertices().size(); ++vertexIdx) {
        Vector3f vertexNormal(0.0f, 0.0f, 0.0f);
        for (const auto& adjacentFace : m_mesh.adjacentFaces(vertexIdx)) {
            vertexNormal += m_mesh.faceNormal(adjacentFace);
        }
        vertexNormal.normalize();
        m_mesh.setVertexNormal(vertexIdx, vertexNormal);
    }

    // Update the OpenGL buffers with the new face and vertex normals
    m_mesh.updateOpenGLBuffers();
}
