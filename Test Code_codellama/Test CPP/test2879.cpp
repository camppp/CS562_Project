void populateIndices(const OpenMesh::ArrayKernel& mesh, const std::string& type, OpenMesh::Handle& handle, int* ptr) {
    if (type == "face_halfedge") {
        FuncFaceHalfedge::call(mesh, handle, ptr);
    } else if (type == "edge_halfedge") {
        FuncEdgeHalfedge::call(mesh, handle, ptr);
    } else if (type == "halfedge_to_vertex") {
        FuncHalfedgeToVertex::call(mesh, handle, ptr);
    }
}
