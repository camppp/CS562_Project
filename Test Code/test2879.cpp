void populateIndices(const OpenMesh::ArrayKernel& mesh, const std::string& type, OpenMesh::Handle& handle, int* ptr) {
    if (type == "face_halfedge") {
        OpenMesh::HalfedgeHandle heh1, heh2;
        // Obtain the halfedge handles based on the given handle (assuming handle represents a face or other relevant entity)
        // Your code to obtain heh1 and heh2 based on the given handle

        FuncFaceHalfedge::call(mesh, heh1, heh2, ptr);
    } else if (type == "edge_halfedge") {
        OpenMesh::EdgeHandle eh = handle;  // Assuming handle represents an edge
        FuncEdgeHalfedge::call(mesh, eh, ptr);
    } else if (type == "halfedge_to_vertex") {
        OpenMesh::HalfedgeHandle heh = handle;  // Assuming handle represents a halfedge
        FuncHalfedgeToVertex::call(mesh, heh, ptr);
    }
}
